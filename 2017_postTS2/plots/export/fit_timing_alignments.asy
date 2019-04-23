import root;
import pad_layout;

string topDir = "../../export/";

string rp_ids[], rp_labels[];
rp_ids.push("16"); rp_labels.push("45-220-ti");
rp_ids.push("116"); rp_labels.push("56-220-ti");

string planes[] = { "0", "1", "2", "3" };

string channels[] = { "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11" };
//string channels[] = { "0", "1", "2", "3", "4" };

TGraph_errorBar = None;

real fill_min = 6230, fill_max = 6380;

//----------------------------------------------------------------------------------------------------

for (int rpi : rp_ids.keys)
{
	NewPadLabel(rp_labels[rpi]);

	for (int pli : planes.keys)
		NewPadLabel("plane " + planes[pli]);

	for (int chi : channels.keys)
	{
		NewRow();

		NewPadLabel("channel " + channels[chi]);
	
		for (int pli : planes.keys)
		{
			NewPad("fill", "correction$\ung{mm}$");

			string f = topDir + "fit_timing_alignments.root";
			string on = rp_ids[rpi] + "_" + planes[pli] + "_" + channels[chi];

			RootObject graph = RootGetObject(f, on, error=false);
			RootObject fit = RootGetObject(f, on+"#0", error=true);

			if (!graph.valid)
				continue;

			draw(graph, "p", blue, mCi+2pt+blue);

			TF1_x_min = fill_min; TF1_x_max = fill_max;
			draw(fit, red+dashed);

			TF1_x_min = -inf; TF1_x_max = +inf;
			draw(fit, red+1pt);

			limits((fill_min, -0.2), (fill_max, +0.8), Crop);
		}
	}

	GShipout("fit_timing_alignments_" + rp_ids[rpi], hSkip=0mm, vSkip=0mm);
}
