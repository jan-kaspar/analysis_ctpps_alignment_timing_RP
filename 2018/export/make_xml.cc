#include "TFile.h"
#include "TGraph.h"

#include <vector>
#include <map>
#include <string>

#include "../stat.h"

#include "DataFormats/CTPPSDetId/interface/CTPPSDiamondDetId.h"

using namespace std;


void GetMeanCorrection(const string &sector, unsigned int plane, const vector<unsigned int> &channels, const vector<TFile *> &files,
		double &corr_mean, double &corr_stddev)
{
	Stat st(1);

	for (const auto &channel : channels)
	{
		for (const auto &file : files)
		{
			char buf[100];
			sprintf(buf, "%s/residua/plane%u/channel%u/g_results", sector.c_str(), plane, channel);
			TGraph *g_results = (TGraph *) file->Get(buf);
			if (!g_results)
				continue;

			double dummy, r, r_unc;
			g_results->GetPoint(0, dummy, r);
			g_results->GetPoint(1, dummy, r_unc);

			if (r_unc > 0.1)
				continue;

			st.Fill(r);
		}
	}

	corr_mean = st.GetMean(0);
	corr_stddev = st.GetStdDev(0);
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

int main()
{
	// select input data
	vector<string> dirs = {
		"data/phys/fill_7137/ZeroBias",
	};

	// define channels to use: map: sector, plane, piece --> list of channels
	map<Key, vector<Piece>> mapping;

	// 2017
	/*
	mapping[{"sector 45", 16, 0}] = {
		{ 0, {0, 11, 1, 10, 2}, {10, 11} },
		{ 1, {9, 3, 8, 4}, {3, 8} },
		{ 2, {7, 5}, {7} },
		{ 3, {6}, {7} }, // crude approximation
	};

	mapping[{"sector 45", 16, 1}] = {
		{ 0, {0, 11, 1, 10, 2}, {10, 11} },
		{ 1, {9, 3, 8, 4}, {3, 8} },
		{ 2, {7, 5}, {7} },
		{ 3, {6}, {7} }, // crude approximation
	};

	mapping[{"sector 45", 16, 2}] = {
		{ 0, {0, 11, 1, 10}, {10, 11} },
		{ 1, {2, 9, 3, 8, 4}, {3, 8} },
		{ 2, {7}, {7} },
		{ 3, {5, 6}, {7} }, // crude approximation
	};

	mapping[{"sector 45", 16, 3}] = {
		{ 0, {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11}, {10, 11, 3, 8} },
	};

	mapping[{"sector 56", 116, 0}] = {
		{ 0, {0, 11, 1, 10, 2}, {10, 11} },
		{ 1, {9, 3, 8, 4}, {3, 8} },
		{ 2, {7, 5}, {7} },
		{ 3, {6}, {7} }, // crude approximation
	};

	mapping[{"sector 56", 116, 1}] = {
		{ 0, {0, 11, 1, 10, 2}, {10, 11} },
		{ 1, {9, 3, 8, 4}, {3, 8} },
		{ 2, {7, 5}, {7} },
		{ 3, {6}, {7} }, // crude approximation
	};

	mapping[{"sector 56", 116, 2}] = {
		{ 0, {0, 11, 1, 10}, {10, 11} },
		{ 1, {2, 9, 3, 8, 4}, {3, 8} },
		{ 2, {7}, {7} },
		{ 3, {5, 6}, {7} }, // crude approximation
	};

	mapping[{"sector 56", 116, 3}] = {
		{ 0, {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11}, {10, 11, 3, 8} },
	};
	*/

	// 2018
	mapping[{"sector 45", 16, 0}] = {
		{ 0, {0, 11, 1, 10, 2}, {11, 10, 2} },
		{ 1, {9, 3, 8, 4}, {9, 3, 8, 4} },
		{ 2, {7, 5}, {7} },
		{ 3, {6}, {6} },
	};

	mapping[{"sector 45", 16, 1}] = {
		{ 0, {0, 11, 1, 10}, {11, 10} },
		{ 1, {2, 9, 3, 8, 4}, {2, 9, 3, 8, 4} },
		{ 2, {7}, {7} },
		{ 3, {5, 6}, {5} },
	};

	mapping[{"sector 45", 16, 2}] = {
		{ 0, {0, 11, 1, 10}, {11, 10} },
		{ 1, {2, 9, 3, 8}, {9, 3, 8} },
		{ 2, {4, 7}, {4, 7} },
		{ 3, {5, 6}, {5} },
	};

	mapping[{"sector 45", 16, 3}] = {
		{ 0, {0, 11, 1, 10}, {11, 10} },
		{ 1, {2, 9, 3, 8}, {9, 3, 8} },
		{ 2, {4, 7}, {4, 7} },
		{ 3, {5, 6}, {5} },
	};


	mapping[{"sector 56", 116, 0}] = {
		{ 0, {0, 11, 1, 10, 2}, {0, 11, 1, 10, 2} },
		{ 1, {9, 3, 8, 4}, {9, 3, 8, 4} },
		{ 2, {7, 5}, {7} },
		{ 3, {6}, {7} },	// crude approximation
	};

	mapping[{"sector 56", 116, 1}] = {
		{ 0, {0, 11, 1, 10}, {0, 11, 1, 10} },
		{ 1, {2, 9, 3, 8, 4}, {2, 9, 3, 8, 4} },
		{ 2, {7}, {7} },
		{ 3, {5, 6}, {7} },	// crude approximation
	};

	mapping[{"sector 56", 116, 2}] = {
		{ 0, {0, 11, 1, 10}, {0, 11, 10} },
		{ 1, {2, 9, 3, 8}, {9, 3, 8} },
		{ 2, {4, 7}, {4, 7} },
		{ 3, {5, 6}, {7} }, // crude approximation
	};

	mapping[{"sector 56", 116, 3}] = {
		{ 0, {0, 11, 1, 10}, {11, 10} },
		{ 1, {2, 9, 3, 8}, {9, 3, 8} },
		{ 2, {4, 7}, {4, 7} },
		{ 3, {5, 6}, {7} }, // crude approximation
	};


	// open input files
	vector<TFile *> f_ins;
	for (const auto &dir : dirs)
		f_ins.push_back(TFile::Open(("../" + dir + "/distributions.root").c_str()));

	// print header
	printf("<xml DocumentType=\"AlignmentDescription\">\n");
	//printf("  <iov first=\"294730:0\" last=\"302664:0\">\n"); // 2017, pre-TS2
	//printf("  <iov first=\"303615:0\" last=\"306463:0\">\n"); // 2017, post-TS2
	printf("  <iov first=\"314158:0\" last=\"325176:0\">\n"); // 2018

	// process data
	for (const auto &p : mapping)
	{
		for (const auto piece : p.second)
		{
			double corr = 0.;
			double corr_unc = 0.;
			GetMeanCorrection(p.first.sector, p.first.plane, piece.source_channels, f_ins, corr, corr_unc);

			printf("    <!-- RP %u, plane %u, Si piece %u -->\n", p.first.rpDecId, p.first.plane, piece.id);
			for (const auto &ch : piece.target_channels)
			{
				const unsigned int arm = p.first.rpDecId / 100;
				const unsigned int st = (p.first.rpDecId / 10) % 10;
				const unsigned int rp = p.first.rpDecId % 10;
				CTPPSDiamondDetId detId(arm, st, rp, p.first.plane, ch);

				printf("      <!-- channel %2u --> <det id=\"%u\" sh_x=\"%+8.1f\" sh_x_unc=\"%+8.1f\"/>\n", ch, detId.rawId(), -corr*1E3, corr_unc*1E3);
			}
		}
	}

	// print footer
	printf("  </iov>\n");
	printf("</xml>\n");

	return 0;
}
