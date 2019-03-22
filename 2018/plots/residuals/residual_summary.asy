import root;
import pad_layout;

string topDir = "../../";

string rp_sectors[], rp_labels[];
rp_sectors.push("sector 45"); rp_labels.push("sector_45");
rp_sectors.push("sector 56"); rp_labels.push("sector_56");

int planes[] = { 0, 1, 2, 3 };

int channels[];
channels.push(0);
channels.push(1);
channels.push(2);
channels.push(3);
channels.push(4);
channels.push(5);
channels.push(6);
channels.push(7);
channels.push(8);
channels.push(9);
channels.push(10);
channels.push(11);

string dir = "data/phys/fill_7137/ZeroBias";

//yTicksDef = RightTicks(0.1, 0.05);

//----------------------------------------------------------------------------------------------------

string f = topDir + dir + "/distributions.root";

for (int rpi : rp_sectors.keys)
{
	NewPad(false);
	label("\vbox{\hbox{" + replace(dir, "_", "\_") + "}\hbox{" + rp_sectors[rpi] + "}}");

	for (int plane : planes)
	{
		NewPad(false);
		label(format("plane %u", plane));
	}


	for (int chi : channels.keys)
	{
		NewRow();

		NewPad(false);
		label(format("channel %u", channels[chi]));

		for (int plane : planes)
		{
			NewPad("$x_{\rm timing} - x_{\rm tracker}\ung{mm}$");
			scale(Linear, Linear(true));

			string obj_base_path = rp_sectors[rpi] + "/residua/" + format("plane%u", plane) + format("/channel%u", channels[chi]) + "/c_analysis";

			if (! RootGetObject(f, obj_base_path, error=false).valid)
				continue;

			TH1_x_min = -5;
			TH1_x_max = +15;

			draw(RootGetObject(f, obj_base_path + "|h_x_res"), "vl", red);
			draw(RootGetObject(f, obj_base_path + "|g_crossing_1"), "l", blue+1pt);

			string obj_res_path = rp_sectors[rpi] + "/residua/" + format("plane%u", plane) + format("/channel%u", channels[chi]) + "/g_results";
			RootObject obj_res = RootGetObject(f, obj_res_path);

			real ax[] = {0.};
			real ay[] = {0.};

			obj_res.vExec("GetPoint", 0, ax, ay); real corr = ay[0];
			obj_res.vExec("GetPoint", 1, ax, ay); real corr_unc = ay[0];

			/*
			if (channels[chi] == 7)
			{
				currentpad.xTicks = LeftTicks(1.0, 0.5);
				xlimits(-4, +0, Crop);
			} else {
				currentpad.xTicks = LeftTicks(0.5, 0.1);
				xlimits(-2.6, -0.8, Crop);
			}
			*/

			yaxis(XEquals(corr, false), heavygreen+2pt);

			AttachLegend(format("%#.3f", corr));
		}
	}

	GShipout("residual_summary_" + rp_labels[rpi] + ".pdf");
}
