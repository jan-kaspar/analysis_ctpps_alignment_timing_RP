#ifndef _config_h_
#define _config_h_

#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "FWCore/ParameterSetReader/interface/ParameterSetReader.h"

#include <vector>
#include <string>

using namespace std;

//----------------------------------------------------------------------------------------------------

struct SelectionRange
{
	double x_min;
	double x_max;

	SelectionRange(double _xmi=0., double _xma=0.) : x_min(_xmi), x_max(_xma)
	{
	}
};

//----------------------------------------------------------------------------------------------------

struct SectorConfig
{
	bool cut_h_apply;
	double cut_h_a, cut_h_c, cut_h_si;

	bool cut_v_apply;
	double cut_v_a, cut_v_c, cut_v_si;
};

//----------------------------------------------------------------------------------------------------

struct Config
{
	unsigned int fill;
	unsigned int xangle;
	string dataset;

	map<unsigned int, string> rp_tags;

	vector<string> input_files;

	vector<string> alignment_files;

	map<unsigned int, double> alignment_corrections_x;

	bool aligned;

	double n_si;

	SectorConfig sectorConfig45, sectorConfig56;

	int LoadFrom(const string &f);

	void Print(bool print_input_files=false) const;
};

//----------------------------------------------------------------------------------------------------

int Config::LoadFrom(const string &f_in)
{
	rp_tags = {
		{ 23, "L_2_F" },
		{ 3, "L_1_F" },
		{ 103, "R_1_F" },
		{ 123, "R_2_F" }
	};

	const edm::ParameterSet& config = edm::readPSetsFrom(f_in)->getParameter<edm::ParameterSet>("config");

	fill = config.getParameter<unsigned int>("fill");
	xangle = config.getParameter<unsigned int>("xangle");
	dataset = config.getParameter<string>("dataset");

	input_files = config.getParameter<vector<string>>("input_files");

	alignment_files = config.getParameter<vector<string>>("alignment_files");

	const auto &acc = config.getParameter<edm::ParameterSet>("alignment_corrections");
	for (const auto &p : rp_tags)
	{
		const auto &ps = acc.getParameter<edm::ParameterSet>("rp_" + p.second);
		alignment_corrections_x[p.first] = ps.getParameter<double>("de_x");
	}

	aligned = config.getParameter<bool>("aligned");

	n_si = config.getParameter<double>("n_si");

	{
		const auto &sps = config.getParameter<edm::ParameterSet>("sector_45");

		sectorConfig45.cut_h_apply = sps.getParameter<bool>("cut_h_apply");
		sectorConfig45.cut_h_a = sps.getParameter<double>("cut_h_a");
		sectorConfig45.cut_h_c = sps.getParameter<double>("cut_h_c");
		sectorConfig45.cut_h_si = sps.getParameter<double>("cut_h_si");

		sectorConfig45.cut_v_apply = sps.getParameter<bool>("cut_v_apply");
		sectorConfig45.cut_v_a = sps.getParameter<double>("cut_v_a");
		sectorConfig45.cut_v_c = sps.getParameter<double>("cut_v_c");
		sectorConfig45.cut_v_si = sps.getParameter<double>("cut_v_si");
	}

	{
		const auto &sps = config.getParameter<edm::ParameterSet>("sector_56");

		sectorConfig56.cut_h_apply = sps.getParameter<bool>("cut_h_apply");
		sectorConfig56.cut_h_a = sps.getParameter<double>("cut_h_a");
		sectorConfig56.cut_h_c = sps.getParameter<double>("cut_h_c");
		sectorConfig56.cut_h_si = sps.getParameter<double>("cut_h_si");

		sectorConfig56.cut_v_apply = sps.getParameter<bool>("cut_v_apply");
		sectorConfig56.cut_v_a = sps.getParameter<double>("cut_v_a");
		sectorConfig56.cut_v_c = sps.getParameter<double>("cut_v_c");
		sectorConfig56.cut_v_si = sps.getParameter<double>("cut_v_si");
	}

	return 0;
}

//----------------------------------------------------------------------------------------------------

void Config::Print(bool print_input_files) const
{
	if (print_input_files)
	{
		printf("* input files\n");
		for (const auto &f : input_files)
			printf("    %s\n", f.c_str());
		printf("\n");
	}

	printf("* general info\n");
	printf("    fill = %u\n", fill);
	printf("    xangle = %u\n", xangle);
	printf("    dataset = %s\n", dataset.c_str());

	printf("\n");
	printf("* dataset already aligned\n");
	printf("    aligned = %u\n", aligned);

	printf("\n");
	printf("* alignment parameters\n");
	for (const auto &p : alignment_corrections_x)
		printf("    RP %u: de_x = %.3f mm\n", p.first, p.second);

	printf("\n");
	printf("* cuts\n");
	printf("    n_si = %.3f\n", n_si);

	printf("\n");
	printf("* sector 45\n");
	printf("    cut_h: apply = %u, a = %.3f, c = %.3f, si = %.3f\n", sectorConfig45.cut_h_apply, sectorConfig45.cut_h_a, sectorConfig45.cut_h_c, sectorConfig45.cut_h_si);
	printf("    cut_v: apply = %u, a = %.3f, c = %.3f, si = %.3f\n", sectorConfig45.cut_v_apply, sectorConfig45.cut_v_a, sectorConfig45.cut_v_c, sectorConfig45.cut_v_si);
	printf("* sector 56\n");
	printf("    cut_h: apply = %u, a = %.3f, c = %.3f, si = %.3f\n", sectorConfig56.cut_h_apply, sectorConfig56.cut_h_a, sectorConfig56.cut_h_c, sectorConfig56.cut_h_si);
	printf("    cut_v: apply = %u, a = %.3f, c = %.3f, si = %.3f\n", sectorConfig56.cut_v_apply, sectorConfig56.cut_v_a, sectorConfig56.cut_v_c, sectorConfig56.cut_v_si);
}

//----------------------------------------------------------------------------------------------------

Config cfg;

#endif
