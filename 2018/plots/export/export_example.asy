import root;
import pad_layout;

string topDir = "../../";

string dataset = "data/version4/fill_7334/ALL"; real fill_number = 7334;

string rps[], rp_sectors[], rp_labels[];
rps.push("16"); rp_sectors.push("sector 45"); rp_labels.push("sector 45");
rps.push("116"); rp_sectors.push("sector 56"); rp_labels.push("sector 56");

int n_planes = 4;

int n_channels = 12;

real amp = 0.4;

xSizeDef = 10cm;

yTicksDef = RightTicks(0.2, 0.1);
//yTicksDef = RightTicks(0.1, 0.05);

pen p_pens[];
p_pens.push(red);
p_pens.push(blue);
p_pens.push(heavygreen);
p_pens.push(magenta);

bool plot_fits = true;

//----------------------------------------------------------------------------------------------------

pen GetPen(int plane, int ch)
{
	if (plane == 0)
	{
		if (ch == 0 || ch == 11 || ch == 1 || ch == 10 || ch == 2) return p_pens[0];
		if (ch == 9 || ch == 3 || ch == 8 || ch == 4) return p_pens[1];
		if (ch == 7 || ch == 5) return p_pens[2];
		if (ch == 6) return p_pens[3];
	}

	if (plane == 1)
	{
		if (ch == 0 || ch == 11 || ch == 1 || ch == 10) return p_pens[0];
		if (ch == 2 || ch == 9 || ch == 3 || ch == 8 || ch == 4) return p_pens[1];
		if (ch == 7) return p_pens[2];
		if (ch == 5 || ch == 6) return p_pens[3];
	}

	if (plane == 2 || plane == 3)
	{
		if (ch == 0 || ch == 11 || ch == 1 || ch == 10) return p_pens[0];
		if (ch == 2 || ch == 9 || ch == 3 || ch == 8) return p_pens[1];
		if (ch == 4 || ch == 7) return p_pens[2];
		if (ch == 5 || ch == 6) return p_pens[3];
	}

	return black;
}

//----------------------------------------------------------------------------------------------------

NewPad(false);

for (int rpi : rp_sectors.keys)
	NewPadLabel(rp_labels[rpi]);

for (int plane = 0; plane < n_planes; ++plane)
{
	NewRow();

	NewPadLabel(format("plane %u", plane));

	for (int rpi : rp_sectors.keys)
	{
		NewPad("channel", "horizontal shift correction$\ung{mm}$");

		for (int ch = 0; ch < n_channels; ++ch)
		{
			string f = topDir + dataset + "/distributions.root";

			pen p = GetPen(plane, ch);

			string obj_path = rp_sectors[rpi] + "/residua/" + format("plane%u", plane) + format("/channel%u", ch) + "/g_results";
			RootObject obj = RootGetObject(f, obj_path, error=false);

			if (obj.valid)
			{
				real ax[] = {0.};
				real ay[] = {0.};

				obj.vExec("GetPoint", 0, ax, ay); real corr = ay[0];
				obj.vExec("GetPoint", 1, ax, ay); real corr_unc = ay[0];

				if (corr_unc < 0.1)
				{
					real x = ch;

					draw((x, corr), mCi+2pt+p);
					draw((x, corr-corr_unc)--(x, corr+corr_unc), p);
				}
			}

			if (plot_fits)
			{
				string f = topDir + "export/fit_timing_alignments.root";
				RootObject fit = RootGetObject(f, rps[rpi] + format("_%u", plane) + format("_%u", ch) + "#0");

				real v = fit.rExec("Eval", fill_number);

				draw((ch-amp/2., v)--(ch+amp/2, v), p);
			}
		}

		limits((-1, -2), (n_channels, +1.0), Crop);
	}
}

//----------------------------------------------------------------------------------------------------

NewPad(false);
AddToLegend(replace(dataset, "_", "\_"), mCi+2pt);
for (int pi : p_pens.keys)
	AddToLegend(format("diamond/piece %u", pi), p_pens[pi]);

AttachLegend();
