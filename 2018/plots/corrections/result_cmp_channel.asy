import root;
import pad_layout;

string topDir = "../../";

string rp_sectors[], rp_labels[];
rp_sectors.push("sector 45"); rp_labels.push("sector 45");
rp_sectors.push("sector 56"); rp_labels.push("sector 56");

int planes[] = { 0, 1, 2, 3 };

int channels[];
pen ch_pens[];
channels.push(10); ch_pens.push(blue);
channels.push(11); ch_pens.push(cyan);

channels.push(3); ch_pens.push(red);
channels.push(8); ch_pens.push(magenta);

channels.push(7); ch_pens.push(heavygreen);
channels.push(5); ch_pens.push(green);

channels.push(6); ch_pens.push(black);

real amp = 0.4;

string dir = "data/phys/fill_7137/ZeroBias";

yTicksDef = RightTicks(0.5, 0.1);
//yTicksDef = RightTicks(0.1, 0.05);

//----------------------------------------------------------------------------------------------------

string f = topDir + dir + "/distributions.root";

for (int rpi : rp_sectors.keys)
{
	NewPad("plane");

	for (int plane : planes)
	{
		for (int chi : channels.keys)
		{
			string obj_path = rp_sectors[rpi] + "/residua/" + format("plane%u", plane) + format("/channel%u", channels[chi]) + "/g_results";
			RootObject obj = RootGetObject(f, obj_path, error=false);
			if (!obj.valid)
				continue;

			real ax[] = {0.};
			real ay[] = {0.};

			obj.vExec("GetPoint", 0, ax, ay); real corr = ay[0];
			obj.vExec("GetPoint", 1, ax, ay); real corr_unc = ay[0];

			if (corr_unc > 0.1)
				continue;

			real x = plane - amp/2. + chi * amp / (channels.length-1);

			pen p = ch_pens[chi];
			draw((x, corr), mCi+2pt+p);
			draw((x, corr-corr_unc)--(x, corr+corr_unc), p);
		}
	}

	limits((-1, -3.0), (4, +3.0), Crop);

	AttachLegend(rp_labels[rpi]);
}

//----------------------------------------------------------------------------------------------------

NewPad(false);
AddToLegend("(" + replace(dir, "_", "\_") + ")");

for (int chi : channels.keys)
{
	AddToLegend(format("channel %u", channels[chi]), mCi+2pt+ch_pens[chi]);
}

AttachLegend();
