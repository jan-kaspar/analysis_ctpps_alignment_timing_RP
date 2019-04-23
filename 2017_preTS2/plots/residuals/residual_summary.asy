import root;
import pad_layout;

string topDir = "../../";

string rp_sectors[], rp_labels[];
rp_sectors.push("sector 45"); rp_labels.push("sector_45");
rp_sectors.push("sector 56"); rp_labels.push("sector_56");

int planes[] = { 0, 1, 2, 3 };

int channels[];
for (int i = 0; i < 12; ++i)
	channels.push(i);


string dir = "data/version2/fill_6189/SingleMuon";

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

			string obj_base_path = rp_sectors[rpi] + "/residua/" + format("plane%u", plane) + format("/channel%u", channels[chi]) + "/";

			RootObject h_x = RootGetObject(f, obj_base_path + "c_analysis|h_x_res", error=false);
			RootObject g_crossing = RootGetObject(f, obj_base_path + "c_analysis|g_crossing_1", error=false);
			RootObject obj_res = RootGetObject(f, obj_base_path + "g_results", error=false);
			RootObject h_w = RootGetObject(f, obj_base_path + "h_w", error=false);

			if (! h_x.valid)
				continue;

			TH1_x_min = -2;
			TH1_x_max = +3;

			draw(h_x, "vl", red);
			draw(g_crossing, "l", blue+1pt);

			real ax[] = {0.};
			real ay[] = {0.};

			obj_res.vExec("GetPoint", 0, ax, ay); real corr = ay[0];
			obj_res.vExec("GetPoint", 1, ax, ay); real corr_unc = ay[0];
			obj_res.vExec("GetPoint", 2, ax, ay); real width_obs = ay[0];

			real width_exp = h_w.rExec("GetMean");

			//currentpad.xTicks = LeftTicks(0.5, 0.1);
			//xlimits(-2.6, -0.8, Crop);
			currentpad.xTicks = LeftTicks(1., 0.5);
			xlimits(-2., +3., Crop);

			yaxis(XEquals(corr, false), heavygreen+2pt);

			AddToLegend(format("<mean (obs.) = %#.3f", corr));
			AddToLegend(format("<width (obs.) = %#.3f", width_obs));
			AddToLegend(format("<width (exp.) = %#.3f", width_exp));
			AttachLegend();
		}
	}

	GShipout("residual_summary_" + rp_labels[rpi] + ".pdf");
}
