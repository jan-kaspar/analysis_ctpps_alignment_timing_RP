#include "TFile.h"
#include "TGraph.h"

#include <vector>
#include <map>
#include <string>

#include "../stat.h"

using namespace std;

//----------------------------------------------------------------------------------------------------

int GetMeanCorrection(const string &sector, unsigned int plane, unsigned int piece, const vector<TFile *> files, 
		const map<string, map<unsigned int, map<unsigned int, vector<unsigned int>>>> &mapping, double &corr)
{
	const auto sit = mapping.find(sector);
	if (sit == mapping.end())
		return 1;

	const auto pit = sit->second.find(plane);
	if (pit == sit->second.end())
		return 1;

	const auto pcit = pit->second.find(piece);
	if (pcit == pit->second.end())
		return 1;

	const auto &channels = pcit->second;

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

	corr = st.GetMean(0);

	return 0;
}

//----------------------------------------------------------------------------------------------------

int main()
{
	// select input data
	vector<string> dirs = {
		"data/phys/fill_6288/SingleMuon",
	};

	// define channels to use: map: sector, plane, piece --> list of channels
	map<string, map<unsigned int, map<unsigned int, vector<unsigned int>>>> mapping;

	mapping["sector 45"][0][0] = { 10, 11 };
	mapping["sector 45"][0][1] = { 3, 8 };
	mapping["sector 45"][0][2] = { 7 };

	mapping["sector 45"][1][0] = { 10, 11 };
	mapping["sector 45"][1][1] = { 3, 8 };
	mapping["sector 45"][1][2] = { 7 };

	mapping["sector 45"][2][0] = { 10, 11 };
	mapping["sector 45"][2][1] = { 3, 8 };

	mapping["sector 45"][3][0] = { 3, 10, 11 };

	mapping["sector 56"][0][0] = { 10, 11 };
	mapping["sector 56"][0][1] = { 3, 8 };
	mapping["sector 56"][0][2] = { 7 };

	mapping["sector 56"][1][0] = { 10, 11 };
	mapping["sector 56"][1][1] = { 3, 8 };
	mapping["sector 56"][1][2] = { 7 };

	mapping["sector 56"][2][0] = { 10, 11 };
	mapping["sector 56"][2][1] = { 3, 8 };

	mapping["sector 56"][3][0] = { 3, 10, 11 };

	// open input files
	vector<TFile *> f_ins;
	for (const auto &dir : dirs)
		f_ins.push_back(TFile::Open(("../" + dir + "/distributions.root").c_str()));

	// process data
	for (const auto &secp : mapping)
	{
		printf("\n");
		printf("* %s\n", secp.first.c_str());

		for (const auto &plap : secp.second)
		{
			unsigned int plane = plap.first;
			printf("    plane %u: \n", plane);

			for (const auto &piep : plap.second)
			{
				unsigned int piece = piep.first;

				double corr = 0.;
				GetMeanCorrection(secp.first, plane, piece, f_ins, mapping, corr);

				printf("        piece %u: r = %.2f\n", piece, corr);
			}
		}
	}

	printf("-----------------------\n");

	for (unsigned int plane : {0, 1, 2, 3})
	{
		printf("\n");
		printf("%% plane %u\n", plane);

		for (const string &sector : {"45", "56"} )
		{
			//printf("%s: ", sector.c_str());

			for (unsigned int piece : {0, 1, 2, 3})
			{
				double corr = 0.;
				int ret = GetMeanCorrection("sector " + sector, plane, piece, f_ins, mapping, corr);

				if (ret == 0)
					printf(" & \\hbox{corr %s: %.2f}", sector.c_str(), corr);
				else
					printf(" & \\hbox{corr %s: N/A}", sector.c_str());
			}

			printf(" \\cr\n");
		}
	}

	return 0;
}
