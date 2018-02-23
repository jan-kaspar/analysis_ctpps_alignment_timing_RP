import root;
import pad_layout;

string topDir = "../../";

string rp_sectors[], rp_labels[];
rp_sectors.push("sector 45"); rp_labels.push("sector 45");
rp_sectors.push("sector 56"); rp_labels.push("sector 56");

int planes[] = { 0, 1, 2, 3 };

int channel = 3;

real amp = 0.4;

string dirs[] = {
	"data/phys/fill_5976/SingleMuon",
	"data/phys/fill_6026/SingleMuon",
	"data/phys/fill_6054/SingleMuon",
	"data/phys/fill_6142/SingleMuon",
	"data/phys/fill_6147/SingleMuon",
	"data/phys/fill_6189/SingleMuon",
};

yTicksDef = RightTicks(0.1, 0.05);

//----------------------------------------------------------------------------------------------------

for (int rpi : rp_sectors.keys)
{
	NewPad("plane");

	for (int plane : planes)
	{
		for (int diri : dirs.keys)
		{
			string f = topDir + dirs[diri] + "/distributions.root";

			string obj_path = rp_sectors[rpi] + "/residua/" + format("plane%u", plane) + format("/channel%u", channel) + "/g_results";
			RootObject obj = RootGetObject(f, obj_path, error=false);
			if (!obj.valid)
				continue;

			real ax[] = {0.};
			real ay[] = {0.};

			obj.vExec("GetPoint", 0, ax, ay); real corr = ay[0];
			obj.vExec("GetPoint", 1, ax, ay); real corr_unc = ay[0];

			if (corr_unc > 0.1)
				continue;

			real x = plane - amp/2. + diri * amp / (dirs.length-1);

			pen p = StdPen(diri);
			draw((x, corr), mCi+2pt+p);
			draw((x, corr-corr_unc)--(x, corr+corr_unc), p);
		}
	}

	limits((-1, -2.1), (4, -1.4), Crop);

	AttachLegend(rp_labels[rpi]);
}

//----------------------------------------------------------------------------------------------------

NewPad(false);
AddToLegend(format("(channel %u)", channel));

for (int diri : dirs.keys)
{
	AddToLegend(replace(dirs[diri], "_", "\_"), mCi+2pt + StdPen(diri));
}

AttachLegend();
