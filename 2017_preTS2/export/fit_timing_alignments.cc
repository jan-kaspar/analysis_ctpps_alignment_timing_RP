#include "TFile.h"
#include "TGraph.h"

#include <vector>
#include <map>
#include <string>

#include "../stat.h"

#include "DataFormats/CTPPSDetId/interface/CTPPSDiamondDetId.h"
#include "DataFormats/Provenance/interface/EventID.h"

#include "fills_runs.h"

#include "TGraphErrors.h"
#include "TFile.h"
#include "TF1.h"

using namespace std;

//----------------------------------------------------------------------------------------------------

bool GetMeanCorrection(const string &sector, unsigned int plane, const vector<unsigned int> &channels, TFile *file,
		double &corr_mean, double &corr_stddev)
{
	unsigned int n = 0;
	double sw=0., swr=0.;

	for (const auto &channel : channels)
	{
		char buf[100];
		sprintf(buf, "%s/residua/plane%u/channel%u/g_results", sector.c_str(), plane, channel);
		TGraph *g_results = (TGraph *) file->Get(buf);
		if (!g_results)
			continue;

		double dummy, r, r_unc;
		g_results->GetPoint(0, dummy, r);
		g_results->GetPoint(1, dummy, r_unc);

		if (r < -0.2 || r > +0.8)
			continue;

		if (r_unc > 0.1)
			continue;

		const double r_unc_eff = max(r_unc, 0.020);
		const double w = 1./r_unc_eff/r_unc_eff;

		n++;
		sw += w;
		swr += w * r;
	}

	if (n == 0)
		return false;

	corr_mean = swr / sw;
	corr_stddev = 1. / sqrt(sw);

	return true;
}

//----------------------------------------------------------------------------------------------------

struct Key
{
	string sector;
	unsigned int rpDecId;
	unsigned int plane;

	bool operator < (const Key &o) const
	{
		if (sector < o.sector)
			return true;
		if (sector > o.sector)
			return false;

		if (rpDecId < o.rpDecId)
			return true;
		if (rpDecId > o.rpDecId)
			return false;

		if (plane < o.plane)
			return true;
		if (plane > o.plane)
			return false;

		return false;
	}
};

//----------------------------------------------------------------------------------------------------

struct Piece
{
	unsigned int id;
	vector<unsigned int> target_channels;
	vector<unsigned int> source_channels;
};

//----------------------------------------------------------------------------------------------------

struct ChannelData
{
	TGraphErrors *g_corr_vs_fill=NULL;
	TF1 *f_fit;

	void Init()
	{
		g_corr_vs_fill = new TGraphErrors;
	}

	void Fill(unsigned int fill, double corr, double corr_unc)
	{
		if (!g_corr_vs_fill)
			Init();

		int idx = g_corr_vs_fill->GetN();
		g_corr_vs_fill->SetPoint(idx, fill, corr);
		g_corr_vs_fill->SetPointError(idx, 0., corr_unc);
	}
};

//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------

int main()
{
	// initialisation
	InitFillsRuns(false);
	//PrintFillRunMapping();

	string topDir = "../data/version4";

	vector<string> datasets = {
		//"ALL"
		//"DoubleEG",
		"SingleMuon",
		//"ZeroBias",
	};

	// define channels to use: map: sector, plane, piece --> list of channels
	map<Key, vector<Piece>> mapping;

	mapping[{"sector 45", 16, 0}] = {
		{ 0, {0, 11, 1, 10, 2}, {11, 10, 2} },
		{ 1, {9, 3, 8, 4}, {9, 3, 8, 4} },
		{ 2, {7, 5}, {7, 5} },
		{ 3, {6}, {7, 5} }, // crude approximation
	};

	mapping[{"sector 45", 16, 1}] = {
		{ 0, {0, 11, 1, 10, 2}, {0, 11, 1, 10, 2} },
		{ 1, {9, 3, 8, 4}, {9, 3, 8, 4} },
		{ 2, {7, 5}, {7, 5} },
		{ 3, {6}, {7, 5} }, // crude approximation
	};

	mapping[{"sector 45", 16, 2}] = {
		{ 0, {0, 11, 1, 10}, {0, 11, 1, 10} },
		{ 1, {2, 9, 3, 8, 4}, {2, 9, 3, 8, 4} },
		{ 2, {7}, {7} },
		{ 3, {5, 6}, {7} }, // crude approximation
	};

	mapping[{"sector 45", 16, 3}] = {
		{ 0, {0, 1, 2, 3, 4, 5, 6, 9, 10, 11}, {0, 1, 2, 3, 4, 5, 6, 9, 10, 11} },
		{ 10, {7, 8}, {7, 8} },
	};

	mapping[{"sector 56", 116, 0}] = {
		{ 0, {0, 11, 1, 10, 2}, {0, 11, 1, 10, 2} },
		{ 1, {9, 3, 8, 4}, {9, 3, 8, 4} },
		{ 2, {7, 5}, {7, 5} },
		{ 3, {6}, {7, 5} }, // crude approximation
	};

	mapping[{"sector 56", 116, 1}] = {
		{ 0, {0, 11, 1, 10, 2}, {0, 11, 1, 10, 2} },
		{ 1, {9, 3, 8, 4}, {3, 8, 4} },
		{ 2, {7, 5}, {7, 5} },
		{ 3, {6}, {7, 5} }, // crude approximation
	};

	mapping[{"sector 56", 116, 2}] = {
		{ 0, {0, 11, 1, 10}, {0, 11, 1, 10} },
		{ 1, {2, 9, 3, 8, 4}, {2, 9, 3, 8, 4} },
		{ 2, {7}, {7} },
		{ 3, {5, 6}, {7} }, // crude approximation
	};

	mapping[{"sector 56", 116, 3}] = {
		{ 0, {0, 1, 2, 3, 4, 5, 6, 9, 10, 11}, {0, 1, 2, 3, 4, 5, 6, 9, 10, 11} },
		{ 10, {7, 8}, {7, 8} },
	};

	// collect results
	map<unsigned int, ChannelData> channelData;

	for (const auto &fill : fills)
	{
		for (const auto &dataset : datasets)
		{
			// open input file
			char buf[200];
			sprintf(buf, "%s/fill_%u/%s/distributions.root", topDir.c_str(), fill, dataset.c_str());
			TFile *f_in = TFile::Open(buf);

			if (!f_in)
				continue;

			for (const auto &p : mapping)
			{
				for (const auto piece : p.second)
				{
					double corr = 0.;
					double corr_unc = 0.;
					bool valid = GetMeanCorrection(p.first.sector, p.first.plane, piece.source_channels, f_in, corr, corr_unc);

					if (!valid)
						continue;

					//corr_unc = sqrt(corr_unc*corr_unc + 0.025*0.025);

					for (const auto &ch : piece.target_channels)
					{
						const unsigned int arm = p.first.rpDecId / 100;
						const unsigned int st = (p.first.rpDecId / 10) % 10;
						const unsigned int rp = p.first.rpDecId % 10;

						const int idx = arm*100000 + st*10000 + rp*1000 + p.first.plane*100 + ch;
						channelData[idx].Fill(fill, corr, corr_unc);
					}
				}
			}

			delete f_in;
		}
	}

	// fit plots
	for (auto &p : channelData)
	{
		//p.second.f_fit = new TF1("", "[0] + [1]*x");
		p.second.f_fit = new TF1("", "[0]");
		p.second.g_corr_vs_fill->Fit(p.second.f_fit, "Q");
	}

	// open output files
	TFile *f_out = TFile::Open("fit_timing_alignments.root", "recreate");

	// save plots
	for (auto &p : channelData)
	{
		const unsigned int rp = p.first / 1000;
		const unsigned int plane = (p.first / 100) % 10;
		const unsigned int channel = p.first % 100;

		char buf[100];
		sprintf(buf, "%u_%u_%u", rp, plane, channel);
		p.second.g_corr_vs_fill->Write(buf);
	}

	delete f_out;

	// save results
	FILE *f_res = fopen("fit_timing_alignments.xml", "w");

	fprintf(f_res, "<xml DocumentType=\"AlignmentDescription\">\n");

	for (const auto &fill : fills)
	{
		fprintf(f_res, "  <iov first=\"%u:%u\" last=\"%u:%u\"> <!-- fill %u -->\n",
			fills_runs[fill].front(), 0,
			fills_runs[fill].back(), edm::EventID::maxLuminosityBlockNumber(), fill);

		for (auto &p : channelData)
		{
			const unsigned int rpDecId = p.first / 1000;
			const unsigned int plane = (p.first / 100) % 10;
			const unsigned int channel = p.first % 100;

			const unsigned int arm = rpDecId / 100;
			const unsigned int st = (rpDecId / 10) % 10;
			const unsigned int rp = rpDecId % 10;
			CTPPSDiamondDetId detId(arm, st, rp, plane, channel);

			double corr = p.second.f_fit->Eval(fill);

			fprintf(f_res, "      <!-- RP %u, pl %u, ch %2u --> <det id=\"%u\" sh_x=\"%+8.1f\"/>\n",
				rpDecId, plane, channel, detId.rawId(), -corr*1E3);
		}

		fprintf(f_res, "  </iov>\n");
	}

	fprintf(f_res, "</xml>\n");

	fclose(f_res);

	return 0;
}
