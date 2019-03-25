#include "config.h"
#include "stat.h"

#include "TFile.h"
#include "TH1D.h"
#include "TH2D.h"
#include "TProfile.h"
#include "TF1.h"
#include "TGraph.h"
#include "TCanvas.h"

#include "DataFormats/FWLite/interface/Handle.h"
#include "DataFormats/FWLite/interface/ChainEvent.h"

#include "DataFormats/Common/interface/DetSetVector.h"
#include "DataFormats/Common/interface/DetSet.h"

#include "DataFormats/CTPPSDetId/interface/TotemRPDetId.h"
#include "DataFormats/CTPPSDetId/interface/CTPPSDiamondDetId.h"

#include "DataFormats/CTPPSReco/interface/CTPPSDiamondRecHit.h"
#include "DataFormats/CTPPSReco/interface/CTPPSLocalTrackLite.h"

#include <vector>
#include <string>

using namespace std;
using namespace edm;

//----------------------------------------------------------------------------------------------------

void WriteCutPlot(TH2D *h, double a, double c, double si, const string &label)
{
	TCanvas *canvas = new TCanvas();
	canvas->SetName(label.c_str());
	canvas->SetLogz(1);

	h->Draw("colz");

	double x_min = -30.;
	double x_max = +30.;

	TGraph *g_up = new TGraph();
	g_up->SetName("g_up");
	g_up->SetPoint(0, x_min, -a*x_min - c + cfg.n_si * si);
	g_up->SetPoint(1, x_max, -a*x_max - c + cfg.n_si * si);
	g_up->SetLineColor(1);
	g_up->Draw("l");

	TGraph *g_down = new TGraph();
	g_down->SetName("g_down");
	g_down->SetPoint(0, x_min, -a*x_min - c - cfg.n_si * si);
	g_down->SetPoint(1, x_max, -a*x_max - c - cfg.n_si * si);
	g_down->SetLineColor(1);
	g_down->Draw("l");

	canvas->Write();
}

//----------------------------------------------------------------------------------------------------

struct SectorData
{
	string name;

	unsigned int rpIdUp, rpIdDw, rpIdTi;

	SectorConfig scfg;

	// hit distributions
	map<unsigned int, TH1D*> m_h1_x_bef_sel;

	map<unsigned int, TH2D*> m_h2_y_vs_x_bef_sel;

	map<unsigned int, TH2D*> m_h2_y_vs_x_aft_sel;

	// cut plots
	TH1D *h_q_cut_h_bef, *h_q_cut_h_aft;
	TH2D *h2_cut_h_bef, *h2_cut_h_aft;
	TProfile *p_cut_h_aft;

	TH1D *h_q_cut_v_bef, *h_q_cut_v_aft;
	TH2D *h2_cut_v_bef, *h2_cut_v_aft;
	TProfile *p_cut_v_aft;

	// residua distributions
	map<unsigned int, map<unsigned int, TH1D*> > m_h_x_res;

	SectorData(const string _name, unsigned int _rpIdUp, unsigned int _rpIdDw, unsigned int _rpIdTi, const SectorConfig &_scfg);

	unsigned int Process(const vector<CTPPSLocalTrackLite> &tracks, const DetSetVector<CTPPSDiamondRecHit> &diamondHits);

	void MakeFits();

	void AnalyzeOneChannel(TH1D *h, unsigned int plane, unsigned int channel) const;

	void Write() const;
};

//----------------------------------------------------------------------------------------------------

SectorData::SectorData(const string _name, unsigned int _rpIdUp, unsigned int _rpIdDw, unsigned int _rpIdTi, const SectorConfig &_scfg) :
	name(_name), rpIdUp(_rpIdUp), rpIdDw(_rpIdDw), rpIdTi(_rpIdTi), scfg(_scfg)
{
	// binning
	const double bin_size_x = 142.3314E-3; // mm
	const unsigned int n_bins_x = 210;

	const double pixel_x_offset = 0.;

	const double x_min_pix = pixel_x_offset, x_max_pix = pixel_x_offset + n_bins_x * bin_size_x;
	const double x_min_str = 0., x_max_str = n_bins_x * bin_size_x;

	const unsigned int n_bins_y = 200;
	const double y_min = -20., y_max = +20.;

	// hit distributions
	m_h1_x_bef_sel[rpIdUp] = new TH1D("", ";x", 10*n_bins_x, x_min_pix, x_max_pix);
	m_h1_x_bef_sel[rpIdDw] = new TH1D("", ";x", 10*n_bins_x, x_min_pix, x_max_pix);

	m_h2_y_vs_x_bef_sel[rpIdUp] = new TH2D("", ";x;y", n_bins_x, x_min_str, x_max_str, n_bins_y, y_min, y_max);
	m_h2_y_vs_x_bef_sel[rpIdDw] = new TH2D("", ";x;y", n_bins_x, x_min_pix, x_max_pix, n_bins_y, y_min, y_max);

	m_h2_y_vs_x_aft_sel[rpIdUp] = new TH2D("", ";x;y", n_bins_x, x_min_str, x_max_str, n_bins_y, y_min, y_max);
	m_h2_y_vs_x_aft_sel[rpIdDw] = new TH2D("", ";x;y", n_bins_x, x_min_pix, x_max_pix, n_bins_y, y_min, y_max);

	// cut plots
	h_q_cut_h_bef = new TH1D("", ";cq_h", 400, -2., 2.);
	h_q_cut_h_aft = new TH1D("", ";cq_h", 400, -2., 2.);
	h2_cut_h_bef = new TH2D("", ";x_up;x_dw", n_bins_x, x_min_str, x_max_str, n_bins_x, x_min_pix, x_max_pix);
	h2_cut_h_aft = new TH2D("", ";x_up;x_dw", n_bins_x, x_min_str, x_max_str, n_bins_x, x_min_pix, x_max_pix);
	p_cut_h_aft = new TProfile("", ";x_up;mean of x_dw", n_bins_x, x_min_str, x_max_str);

	h_q_cut_v_bef = new TH1D("", ";cq_v", 400, -2., 2.);
	h_q_cut_v_aft = new TH1D("", ";cq_v", 400, -2., 2.);
	h2_cut_v_bef = new TH2D("", ";y_up;y_dw", n_bins_y, y_min, y_max, n_bins_y, y_min, y_max);
	h2_cut_v_aft = new TH2D("", ";y_up;y_dw", n_bins_y, y_min, y_max, n_bins_y, y_min, y_max);
	p_cut_v_aft = new TProfile("", ";y_up;mean of y_dw", n_bins_y, y_min, y_max);

	// residua histograms
	for (unsigned int pl = 0; pl < 4; ++pl)
		for (unsigned int ch = 0; ch < 12; ++ch)
			m_h_x_res[pl][ch] = new TH1D("", ";x_res", 1200., -7., +5.);
}

//----------------------------------------------------------------------------------------------------

unsigned int SectorData::Process(const vector<CTPPSLocalTrackLite> &tracks, const DetSetVector<CTPPSDiamondRecHit> &diamondHits)
{
	// build a collection of upstream and downstream (corrected) tracks
	vector<CTPPSLocalTrackLite> tracksUp, tracksDw;

	for (const auto &tr : tracks)
	{
		CTPPSDetId rpId(tr.getRPId());
		unsigned int rpDecId = rpId.arm()*100 + rpId.station()*10 + rpId.rp();

		if (rpDecId != rpIdUp && rpDecId != rpIdDw)
			continue;

		double x = tr.getX();
		double y = tr.getY();

		// apply alignment corrections
		if (!cfg.aligned)
			x += cfg.alignment_corrections_x[rpDecId];

		// re-build track object
		CTPPSLocalTrackLite tr_corr(tr.getRPId(), x, 0., y, 0.,
			0., 0., 0., 0., 0., (CTPPSpixelLocalTrackReconstructionInfo)0, 0, 0., 0.);

		// store corrected track into the right collection
		if (rpDecId == rpIdUp)
			tracksUp.push_back(std::move(tr_corr));
		if (rpDecId == rpIdDw)
			tracksDw.push_back(std::move(tr_corr));
	}

	// update plots before selection
	for (const auto &tr : tracksUp)
	{
		m_h1_x_bef_sel[rpIdUp]->Fill(tr.getX());
		m_h2_y_vs_x_bef_sel[rpIdUp]->Fill(tr.getX(), tr.getY());
	}

	for (const auto &tr : tracksDw)
	{
		m_h1_x_bef_sel[rpIdDw]->Fill(tr.getX());
		m_h2_y_vs_x_bef_sel[rpIdDw]->Fill(tr.getX(), tr.getY());
	}

	// skip crowded events
	if (tracksUp.size() > 1)
		return 0;

	if (tracksDw.size() > 1)
		return 0;

	// do the selection
	unsigned int pairs_selected = 0;

	for (const auto &trUp : tracksUp)
	{
		for (const auto &trDw : tracksDw)
		{
			h2_cut_h_bef->Fill(trUp.getX(), trDw.getX());
			h2_cut_v_bef->Fill(trUp.getY(), trDw.getY());

			const double cq_h = trDw.getX() + scfg.cut_h_a * trUp.getX() + scfg.cut_h_c;
			h_q_cut_h_bef->Fill(cq_h);
			const bool cv_h = (fabs(cq_h) < cfg.n_si * scfg.cut_h_si);

			const double cq_v = trDw.getY() + scfg.cut_v_a * trUp.getY() + scfg.cut_v_c;
			h_q_cut_v_bef->Fill(cq_v);
			const bool cv_v = (fabs(cq_v) < cfg.n_si * scfg.cut_v_si);

			bool cuts_passed = true;
			if (scfg.cut_h_apply)
				cuts_passed &= cv_h;
			if (scfg.cut_v_apply)
				cuts_passed &= cv_v;

			if (!cuts_passed)
				continue;

			h_q_cut_h_aft->Fill(cq_h);
			h_q_cut_v_aft->Fill(cq_v);

			h2_cut_h_aft->Fill(trUp.getX(), trDw.getX());
			h2_cut_v_aft->Fill(trUp.getY(), trDw.getY());

			p_cut_h_aft->Fill(trUp.getX(), trDw.getX());
			p_cut_v_aft->Fill(trUp.getY(), trDw.getY());

			m_h2_y_vs_x_aft_sel[rpIdUp]->Fill(trUp.getX(), trUp.getY());
			m_h2_y_vs_x_aft_sel[rpIdDw]->Fill(trDw.getX(), trDw.getY());

			// loop over diamond hits
			bool correspondingDiamondHit = false;
			for (const auto &diRPSet : diamondHits)
			{
				CTPPSDiamondDetId padId(diRPSet.detId());
				const unsigned int rpDecId = padId.arm()*100 + padId.station()*10 + padId.rp();
				const unsigned int plane = padId.plane();
				const unsigned int channel = padId.channel();

				if (rpDecId != rpIdTi)
					continue;

				correspondingDiamondHit = true;

				double z_up = 212.55;
				double z_dw = 219.55;
				double z_ti = 215.70;

				double a = (trDw.getX() - trUp.getX()) / (z_dw - z_up);
				double b = trDw.getX() - a * z_dw;
				double x_ti = a * z_ti + b;

				for (const auto &hit : diRPSet)
				{
					double x_res = hit.getX() - x_ti;
					m_h_x_res[plane][channel]->Fill(x_res);
				}
			}

			if (correspondingDiamondHit)
				pairs_selected++;
		}
	}

	return pairs_selected;
}

//----------------------------------------------------------------------------------------------------

void SectorData::MakeFits()
{
}

//----------------------------------------------------------------------------------------------------

void SectorData::Write() const
{
	TDirectory *d_top = gDirectory;

	TDirectory *d_sector = d_top->mkdir(name.c_str());

	// before selection
	TDirectory *d_bef_sel = d_sector->mkdir("before selection");
	for (const auto &p : m_h2_y_vs_x_bef_sel)
	{
		gDirectory = d_bef_sel->mkdir(cfg.rp_tags[p.first].c_str());

		const auto it = m_h1_x_bef_sel.find(p.first);
		it->second->Write("h_x");

		p.second->Write("h2_y_vs_x");
	}

	// cut plots
	TDirectory *d_cuts = d_sector->mkdir("cuts");

	gDirectory = d_cuts->mkdir("cut_h");
	h_q_cut_h_bef->Write("h_q_cut_h_bef");
	h_q_cut_h_aft->Write("h_q_cut_h_aft");
	WriteCutPlot(h2_cut_h_bef, scfg.cut_h_a, scfg.cut_h_c, scfg.cut_h_si, "canvas_before");
	WriteCutPlot(h2_cut_h_aft, scfg.cut_h_a, scfg.cut_h_c, scfg.cut_h_si, "canvas_after");
	p_cut_h_aft->Write("p_cut_h_aft");

	gDirectory = d_cuts->mkdir("cut_v");
	h_q_cut_v_bef->Write("h_q_cut_v_bef");
	h_q_cut_v_aft->Write("h_q_cut_v_aft");
	WriteCutPlot(h2_cut_v_bef, scfg.cut_v_a, scfg.cut_v_c, scfg.cut_v_si, "canvas_before");
	WriteCutPlot(h2_cut_v_aft, scfg.cut_v_a, scfg.cut_v_c, scfg.cut_v_si, "canvas_after");
	p_cut_v_aft->Write("p_cut_v_aft");

	// after selection
	TDirectory *d_aft_sel = d_sector->mkdir("after selection");
	for (const auto &p : m_h2_y_vs_x_aft_sel)
	{
		gDirectory = d_aft_sel->mkdir(cfg.rp_tags[p.first].c_str());
		p.second->Write("h2_y_vs_x");
	}

	// residua histograms
	TDirectory *d_residua = d_sector->mkdir("residua");
	for (const auto &pp : m_h_x_res)
	{
		char buf[100];
		sprintf(buf, "plane%u", pp.first);
		TDirectory *d_pl = d_residua->mkdir(buf);

		for (const auto &p : pp.second)
		{
			sprintf(buf, "channel%u", p.first);
			gDirectory = d_pl->mkdir(buf);

			p.second->SetName("h_x_res");
			p.second->Write();

			// process
			AnalyzeOneChannel(p.second, pp.first, p.first);
		}
	}

	// clean up
	gDirectory = d_top;
}

//----------------------------------------------------------------------------------------------------

void SectorData::AnalyzeOneChannel(TH1D *h, unsigned int plane, unsigned int channel) const
{
	// define central region
	double cen_min=0, cen_max=1;
	if (name == "sector 45") { cen_min = -2.0; cen_max = -1.8; }
	if (name == "sector 56") { cen_min = -1.9; cen_max = -1.7; }

	// calculate average value in the central region
	int bin_min = h->FindBin(cen_min);
	int bin_max = h->FindBin(cen_max);
	double cen_avg = 0.;
	for (int bin = bin_min; bin <= bin_max; ++bin)
		cen_avg += h->GetBinContent(bin);
	cen_avg /= (bin_max - bin_min + 1);

	// skip is statistics too low
	if (cen_avg < 10)
		return;

	// prepare canvas
	TCanvas *c = new TCanvas();
	h->Draw();

	// define crossing levels
	vector<double> levels_min = { 0.3, 0.5, 0.7 };
	vector<double> levels_max = { 0.3, 0.5, 0.7 };

	if (plane < 3 && channel == 7)
		levels_min = { 0.10, 0.15, 0.20 };

	// find crossings for all levels
	vector<double> x_centres;

	for (unsigned int li = 0; li < levels_min.size(); ++li)
	{
		bin_min = h->GetNbinsX();
		bin_max = 0;

		for (int bin = 1; bin < h->GetNbinsX(); ++bin)
		{
			if (h->GetBinContent(bin) >= levels_min[li] * cen_avg)
			{
				bin_min = bin;
				break;
			}
		}

		for (int bin = h->GetNbinsX()-1; bin > 0; --bin)
		{
			if (h->GetBinContent(bin) >= levels_max[li] * cen_avg)
			{
				bin_max = bin;
				break;
			}
		}

		const double x_min = h->GetBinCenter(bin_min);
		const double x_max = h->GetBinCenter(bin_max);
		const double x_centre = (x_max + x_min) / 2.;
		x_centres.push_back(x_centre);

		TGraph *g = new TGraph();
	
		char buf[100];
		sprintf(buf, "g_crossing_%u", li);
		g->SetName(buf);

		g->SetPoint(0, -3., 0.);
		g->SetPoint(1, x_min, 0.);
		g->SetPoint(2, x_min, cen_avg);
		g->SetPoint(3, x_max, cen_avg);
		g->SetPoint(4, x_max, 0.);
		g->SetPoint(5, 0., 0.);

		g->Draw("l");
	}

	// save plots
	c->Write("c_analysis");

	// calculate overall result
	double r_min = 1E100, r_max = -1E100;
	double S_r = 0.;
	for (const auto &r : x_centres)
	{
		r_min = min(r_min, r);
		r_max = max(r_max, r);

		S_r += r;
	}

	const double r_avg = S_r / x_centres.size();
	const double r_unc = r_max - r_min;

	// save results
	TGraph *g_results = new TGraph();
	g_results->SetName("g_results");
	g_results->SetPoint(0, 0, r_avg);
	g_results->SetPoint(1, 1, r_unc);
	g_results->Write();
}

//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------

int main()
{
	// load config
	if (cfg.LoadFrom("config.py") != 0)
	{
		printf("ERROR: cannot load config.\n");
		return 1;
	}

	// TODO
	//if (cfg.input_files.size() > 5)
	//	cfg.input_files.resize(5);

	printf("-------------------- config ----------------------\n");
	cfg.Print(true);
	printf("--------------------------------------------------\n");

	// setup input
	fwlite::ChainEvent ev(cfg.input_files);

	printf("* events in input chain: %llu\n", ev.size());

	// ouput file
	TFile *f_out = new TFile("distributions.root", "recreate");

	// book data structures
	SectorData sectorData45("sector 45", 3, 23, 16, cfg.sectorConfig45);
	SectorData sectorData56("sector 56", 103, 123, 116, cfg.sectorConfig56);

	// loop over the chain entries
	unsigned long int ev_count = 0;
	unsigned long int ev_sel_count_45 = 0;
	unsigned long int ev_sel_count_56 = 0;
	for (ev.toBegin(); ! ev.atEnd(); ++ev)
	{
		ev_count++;

		// get timing hits
		fwlite::Handle< DetSetVector<CTPPSDiamondRecHit> > hDiamondHits;
		hDiamondHits.getByLabel(ev, "ctppsDiamondRecHits");

		// get track data
		fwlite::Handle< vector<CTPPSLocalTrackLite> > hTracks;
		hTracks.getByLabel(ev, "ctppsLocalTrackLiteProducer");

		// process tracks
		if (sectorData45.Process(*hTracks, *hDiamondHits))
			ev_sel_count_45++;

		if (sectorData56.Process(*hTracks, *hDiamondHits))
			ev_sel_count_56++;
	}

	printf("* events processed: %lu\n", ev_count);
	printf("* events selected in 45: %lu\n", ev_sel_count_45);
	printf("* events selected in 56: %lu\n", ev_sel_count_56);

	// save histograms
	gDirectory = f_out;

	// make fits
	sectorData45.MakeFits();
	sectorData56.MakeFits();

	// save histograms
	sectorData45.Write();
	sectorData56.Write();

	// clean up
	delete f_out;
	return 0;
}
