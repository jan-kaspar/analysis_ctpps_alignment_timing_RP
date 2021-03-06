import root;
import pad_layout;

string datasets[];
/*
datasets.push("fill_6617/ALL");
datasets.push("fill_6729/ALL");
datasets.push("fill_6923/ALL");
datasets.push("fill_7039/ALL");
datasets.push("fill_7137/ALL");
datasets.push("fill_7315/ALL");
*/

datasets.push("fill_6617/ALL");
datasets.push("fill_6639/ALL");
datasets.push("fill_6674/ALL");
datasets.push("fill_6700/ALL");
datasets.push("fill_6729/ALL");
datasets.push("fill_6770/ALL");
datasets.push("fill_6901/ALL");
datasets.push("fill_6923/ALL");
datasets.push("fill_6998/ALL");
datasets.push("fill_7039/ALL");
datasets.push("fill_7087/ALL");
datasets.push("fill_7137/ALL");
datasets.push("fill_7234/ALL");
datasets.push("fill_7315/ALL");
datasets.push("fill_7334/ALL");

string topDir = "../../data/version4/";

string sectors[];
sectors.push("sector 45");
sectors.push("sector 56");

string cuts[], c_labels[];
real c_mins[], c_maxs[], c_Ticks[], c_ticks[];
cuts.push("cut_h"); c_labels.push("cut h"); c_mins.push(-1.0); c_maxs.push(+1.0); c_Ticks.push(0.50); c_ticks.push(0.1);

cuts.push("cut_v"); c_labels.push("cut v"); c_mins.push(-1.0); c_maxs.push(+1.0); c_Ticks.push(0.5); c_ticks.push(0.1);

xSizeDef = 8cm;

//----------------------------------------------------------------------------------------------------

NewPad(false);

for (int sci : sectors.keys)
{
	for (int cti : cuts.keys)
	{
		NewPad(false);
		label("\vbox{\SetFontSizesXX\hbox{"+sectors[sci]+"}\hbox{"+c_labels[cti]+"}}");
	}
}

for (int dsi : datasets.keys)
{
	NewRow();

	NewPadLabel(replace(datasets[dsi], "_", "\_"));
	
	for (int sci : sectors.keys)
	{
		for (int cti : cuts.keys)
		{
			NewPad();
			currentpad.xTicks = LeftTicks(c_Ticks[cti], c_ticks[cti]);
			
			real x_min = c_mins[cti];
			real x_max = c_maxs[cti];

			TH1_x_min = x_min;
			TH1_x_max = x_max;


			string f = topDir + datasets[dsi] + "/distributions.root";
			string obj_path = sectors[sci] + "/cuts/" + cuts[cti] + "/h_q_" + cuts[cti] + "_aft";

			pen p = red;

			RootObject obj = RootGetObject(f, obj_path, error=false);
			if (obj.valid)
				draw(obj, "d0,vl,N", p);	

			xlimits(x_min, x_max, Crop);
		}
	}
}
