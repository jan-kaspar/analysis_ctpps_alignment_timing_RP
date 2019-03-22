import root;
import pad_layout;

string topDir = "../../";

string rp_sectors[], rp_labels[];
rp_sectors.push("sector 45"); rp_labels.push("sector_45");
rp_sectors.push("sector 56"); rp_labels.push("sector_56");

int planes[] = { 0, 1, 2, 3 };

int channels[];

// piece 1
channels.push(0);
channels.push(11);
channels.push(1);
channels.push(10);

// piece 1 or 2
channels.push(2);

// piece 2
channels.push(9);
channels.push(3);
channels.push(8);
channels.push(4);

// piece 3
channels.push(7);

// piece 3 or 4
channels.push(5);
channels.push(6);

string dir = "data/phys/fill_6288/SingleMuon";

//yTicksDef = RightTicks(0.1, 0.05);

//----------------------------------------------------------------------------------------------------

string f = topDir + dir + "/distributions.root";

for (int rpi : rp_sectors.keys)
{
	NewPad(false);

	for (int plane : planes)
	{
		NewPadLabel(format("plane %u", plane));
	}

	for (int chi : channels.keys)
	{
		NewRow();

		NewPadLabel(format("channel %u", channels[chi]));

		for (int plane : planes)
		{
			NewPad("$x_{\rm timing} - x_{\rm tracker}\ung{mm}$");
			scale(Linear, Linear(true));

			string obj_base_path = rp_sectors[rpi] + "/residua/" + format("plane%u", plane) + format("/channel%u", channels[chi]) + "/c_analysis";

			if (! RootGetObject(f, obj_base_path, error=false).valid)
				continue;

			draw(RootGetObject(f, obj_base_path + "|h_x_res"), "vl", red);
			draw(RootGetObject(f, obj_base_path + "|g_crossing_1"), "l", blue+1pt);

			string obj_res_path = rp_sectors[rpi] + "/residua/" + format("plane%u", plane) + format("/channel%u", channels[chi]) + "/g_results";
			RootObject obj_res = RootGetObject(f, obj_res_path);

			real ax[] = {0.};
			real ay[] = {0.};

			obj_res.vExec("GetPoint", 0, ax, ay); real corr = ay[0];
			obj_res.vExec("GetPoint", 1, ax, ay); real corr_unc = ay[0];

			if (channels[chi] == 7)
				xlimits(-4, +0, Crop);
			else
				xlimits(-2.6, -0.8, Crop);

			yaxis(XEquals(corr, false), heavygreen+2pt);

			AttachLegend(format("%#.3f", corr));
		}
	}

	GShipout("residual_summary_" + rp_labels[rpi] + ".pdf");
}
