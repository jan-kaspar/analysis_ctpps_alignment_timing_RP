import root;
import pad_layout;

string topDir = "../../";

string rp_sector = "sector 56";
int plane = 0;
int channel = 10;

string dir = "data/phys/fill_6288/SingleMuon";

xSizeDef = 8cm;

//----------------------------------------------------------------------------------------------------

string f = topDir + dir + "/distributions.root";

{
	NewPad("$x_{\rm timing} - x_{\rm tracker}\ung{mm}$");
	scale(Linear, Linear(true));

	string obj_base_path = rp_sector + "/residua/" + format("plane%u", plane) + format("/channel%u", channel) + "/c_analysis";

	draw(RootGetObject(f, obj_base_path + "|h_x_res"), "vl", red);
	draw(RootGetObject(f, obj_base_path + "|g_crossing_1"), "l", blue+1pt);

	string obj_res_path = rp_sector + "/residua/" + format("plane%u", plane) + format("/channel%u", channel) + "/g_results";
	RootObject obj_res = RootGetObject(f, obj_res_path);

	real ax[] = {0.};
	real ay[] = {0.};

	obj_res.vExec("GetPoint", 0, ax, ay); real corr = ay[0];
	obj_res.vExec("GetPoint", 1, ax, ay); real corr_unc = ay[0];

	xlimits(-2.6, -0.8, Crop);

	yaxis(XEquals(corr, false), heavygreen+2pt);

	//AttachLegend(format("%#.3f", corr));
}
