#include <map>
#include <vector>

std::map<unsigned int, std::vector<unsigned int>> fills_runs;

std::vector<unsigned int> fills;

struct FillReference
{
	unsigned int sector45 = 0, sector56 = 0;
};

std::map<unsigned int, FillReference> fills_reference;

void InitFillsRuns(bool useExceptionList = true)
{
	// mapping fill -> runs, from DAS
	fills_runs[5839] = {297046, 297047, 297048, 297049, 297050};
	fills_runs[5840] = {297056, 297057};
	fills_runs[5842] = {297099, 297100, 297101};
	fills_runs[5845] = {297113, 297114};
	fills_runs[5848] = {297168, 297169, 297170, 297171, 297172, 297173, 297174, 297175, 297176, 297177, 297178, 297179, 297180, 297181, 297182};
	fills_runs[5849] = {297211, 297215, 297218, 297219, 297224, 297225, 297227, 297228, 297229};
	fills_runs[5856] = {297281, 297282, 297283, 297284, 297285, 297286, 297287, 297288, 297289, 297290, 297291, 297292, 297293, 297296, 297308, 297316};
	fills_runs[5862] = {297359};
	fills_runs[5864] = {297411};
	fills_runs[5865] = {297424, 297425, 297426, 297427, 297428, 297429, 297430, 297431, 297432, 297433, 297434, 297435};
	fills_runs[5868] = {297467, 297468, 297469};
	fills_runs[5870] = {297474};
	fills_runs[5872] = {297483, 297484, 297485, 297486, 297487, 297488};
	fills_runs[5873] = {297494, 297495, 297496, 297497, 297498, 297499, 297500, 297501, 297502, 297503, 297504, 297505};
	fills_runs[5876] = {297557, 297558, 297559, 297560, 297562, 297563};
	fills_runs[5878] = {297598, 297599, 297603, 297604, 297605, 297606};
	fills_runs[5880] = {297620};
	fills_runs[5882] = {297656, 297657, 297658, 297659, 297660, 297661, 297662, 297663, 297664, 297665, 297666};
	fills_runs[5883] = {297670, 297671, 297672, 297673, 297674, 297675, 297678};
	fills_runs[5885] = {297713, 297714, 297715};
	fills_runs[5887] = {297722, 297723};
	fills_runs[5919] = {298653};
	fills_runs[5920] = {298673, 298674, 298678, 298679, 298681};
	fills_runs[5930] = {298809};
	fills_runs[5934] = {298853, 298854, 298855};
	fills_runs[5942] = {298996, 298997, 298998, 299000};
	fills_runs[5946] = {299042};
	fills_runs[5950] = {299061, 299062, 299064, 299065, 299067};
	fills_runs[5952] = {299096};
	fills_runs[5954] = {299149};
	fills_runs[5958] = {299178, 299180, 299183, 299184, 299185};
	fills_runs[5960] = {299316, 299317, 299318, 299322, 299324, 299325, 299326, 299327, 299329};
	fills_runs[5962] = {299368, 299369, 299370};
	fills_runs[5963] = {299380, 299381};
	fills_runs[5965] = {299393, 299394, 299395, 299396};
	fills_runs[5966] = {299420};
	fills_runs[5971] = {299443};
	fills_runs[5974] = {299450};
	fills_runs[5976] = {299477, 299478, 299479, 299480, 299481};
	fills_runs[5979] = {299592, 299593, 299594, 299595, 299597, 299598};
	fills_runs[5980] = {299614, 299616, 299617};
	fills_runs[5984] = {299649, 299650};
	fills_runs[6012] = {299996};
	fills_runs[6015] = {300007};
	fills_runs[6016] = {300015, 300016, 300017, 300018, 300019, 300027, 300029, 300043, 300049, 300050};
	fills_runs[6018] = {300079};
	fills_runs[6019] = {300087, 300088};
	fills_runs[6020] = {300104, 300105, 300106, 300107};
	fills_runs[6021] = {300117};
	fills_runs[6024] = {300122, 300123, 300124};
	fills_runs[6026] = {300155, 300156, 300157};
	fills_runs[6030] = {300226};
	fills_runs[6031] = {300233, 300234, 300235, 300236, 300237, 300238, 300239, 300240, 300241};
	fills_runs[6035] = {300280, 300281, 300282, 300283, 300284};
	fills_runs[6041] = {300364, 300365, 300366, 300367, 300368, 300369, 300370, 300371, 300372, 300373, 300374, 300375};
	fills_runs[6044] = {300389, 300390, 300391, 300392, 300393, 300394, 300395, 300396, 300397, 300398, 300399, 300400, 300401};
	fills_runs[6046] = {300459, 300461, 300462, 300463, 300464, 300466, 300467};
	fills_runs[6048] = {300497, 300498, 300499, 300500};
	fills_runs[6050] = {300514, 300515, 300516, 300517};
	fills_runs[6052] = {300538, 300539, 300545, 300548, 300551, 300552, 300558, 300560, 300561};
	fills_runs[6053] = {300574, 300575, 300576};
	fills_runs[6054] = {300631, 300632, 300633, 300635, 300636};
	fills_runs[6055] = {300673, 300674, 300675, 300676};
	fills_runs[6057] = {300742};
	fills_runs[6060] = {300777, 300780, 300781, 300785};
	fills_runs[6061] = {300806, 300811, 300812, 300816, 300817};
	fills_runs[6072] = {301046};
	fills_runs[6079] = {301086, 301087, 301088};
	fills_runs[6082] = {301141, 301142};
	fills_runs[6084] = {301161, 301165};
	fills_runs[6086] = {301179, 301180, 301183};
	fills_runs[6089] = {301281, 301283};
	fills_runs[6090] = {301298};
	fills_runs[6091] = {301323};
	fills_runs[6093] = {301330};
	fills_runs[6094] = {301359};
	fills_runs[6096] = {301383, 301384};
	fills_runs[6097] = {301391, 301392, 301393, 301394, 301395, 301396, 301397, 301398, 301399};
	fills_runs[6098] = {301417};
	fills_runs[6104] = {301447, 301448, 301449, 301450};
	fills_runs[6105] = {301461};
	fills_runs[6106] = {301472, 301473, 301474, 301475, 301476, 301480};
	fills_runs[6110] = {301519, 301521, 301524, 301525, 301526, 301528, 301529, 301530, 301531, 301532};
	fills_runs[6114] = {301567};
	fills_runs[6116] = {301627};
	fills_runs[6119] = {301664, 301665};
	fills_runs[6123] = {301694};
	fills_runs[6136] = {301912, 301913, 301914};
	fills_runs[6138] = {301941};
	fills_runs[6140] = {301959, 301960};
	fills_runs[6141] = {301969, 301970};
	fills_runs[6142] = {301984, 301985, 301986, 301987};
	fills_runs[6143] = {301997, 301998};
	fills_runs[6146] = {302019};
	fills_runs[6147] = {302026, 302027, 302029, 302030, 302031, 302032, 302033, 302034, 302036, 302037, 302038, 302040, 302041, 302042, 302043, 302044};
	fills_runs[6152] = {302131, 302132};
	fills_runs[6155] = {302159};
	fills_runs[6156] = {302163, 302165, 302166};
	fills_runs[6158] = {302225};
	fills_runs[6159] = {302228, 302229};
	fills_runs[6160] = {302239, 302240};
	fills_runs[6161] = {302262, 302263};
	fills_runs[6165] = {302277, 302278, 302279, 302280};
	fills_runs[6167] = {302322};
	fills_runs[6168] = {302328};
	fills_runs[6169] = {302337, 302342, 302343, 302344, 302349, 302350};
	fills_runs[6170] = {302388};
	fills_runs[6171] = {302392, 302393};
	fills_runs[6174] = {302448};
	fills_runs[6175] = {302472, 302473, 302474, 302475, 302476};
	fills_runs[6176] = {302479};
	fills_runs[6177] = {302484, 302485, 302486, 302487, 302488, 302489, 302490, 302491, 302492, 302493, 302494};
	fills_runs[6179] = {302509};
	fills_runs[6180] = {302513};
	fills_runs[6182] = {302522, 302523, 302524, 302525, 302526};
	fills_runs[6185] = {302548, 302549, 302550, 302551, 302552, 302553, 302554, 302555};
	fills_runs[6186] = {302563, 302564, 302565, 302566, 302567, 302569, 302570, 302571, 302572, 302573};
	fills_runs[6189] = {302596, 302597};
	fills_runs[6191] = {302634, 302635};
	fills_runs[6192] = {302646, 302649, 302650, 302651, 302654};
	fills_runs[6193] = {302660, 302661, 302662, 302663};

	// fills to process (CMS golden & RPs inserted)
    fills.push_back(5839);
    fills.push_back(5840);
    fills.push_back(5842);
    fills.push_back(5845);
    fills.push_back(5848);
    fills.push_back(5849);
    fills.push_back(5856);
    fills.push_back(5864);
    fills.push_back(5865);
    fills.push_back(5868);
    fills.push_back(5942);
    fills.push_back(5946);
    fills.push_back(5950);
    fills.push_back(5952);
    fills.push_back(5954);
    fills.push_back(5958);
    fills.push_back(5960);
    fills.push_back(5962);
    fills.push_back(5963);
    fills.push_back(5965);
    fills.push_back(5966);
    fills.push_back(5971);
    fills.push_back(5974);
    fills.push_back(5976);
    fills.push_back(5979);
    fills.push_back(5984);
    fills.push_back(6019);
    fills.push_back(6020);
    fills.push_back(6024);
    fills.push_back(6026);
    fills.push_back(6030);
    fills.push_back(6031);
    fills.push_back(6035);
    fills.push_back(6041);
    fills.push_back(6044);
    fills.push_back(6046);
    fills.push_back(6048);
    fills.push_back(6050);
    fills.push_back(6052);
    fills.push_back(6053);
    fills.push_back(6054);
    fills.push_back(6055);
    fills.push_back(6057);
    fills.push_back(6060);
    fills.push_back(6061);
    fills.push_back(6084);
    fills.push_back(6086);
    fills.push_back(6089);
    fills.push_back(6090);
    fills.push_back(6091);
    fills.push_back(6093);
    fills.push_back(6094);
    fills.push_back(6096);
    fills.push_back(6097);
    fills.push_back(6098);
    fills.push_back(6106);
    fills.push_back(6110);
    fills.push_back(6114);
    fills.push_back(6116);
    fills.push_back(6119);
    fills.push_back(6123);
    fills.push_back(6136);
    fills.push_back(6138);
    fills.push_back(6140);
    fills.push_back(6141);
    fills.push_back(6142);
    fills.push_back(6143);
    fills.push_back(6146);
    fills.push_back(6147);
    fills.push_back(6152);
    fills.push_back(6155);
    fills.push_back(6156);
    fills.push_back(6158);
    fills.push_back(6159);
    fills.push_back(6160);
    fills.push_back(6161);
    fills.push_back(6165);
    fills.push_back(6167);
    fills.push_back(6168);
    fills.push_back(6169);
    fills.push_back(6170);
    fills.push_back(6171);
    fills.push_back(6174);
    fills.push_back(6175);
    fills.push_back(6176);
    fills.push_back(6177);
    fills.push_back(6179);
    fills.push_back(6180);
    fills.push_back(6182);
    fills.push_back(6185);
    fills.push_back(6186);
    fills.push_back(6189);
    fills.push_back(6191);
    fills.push_back(6192);
    fills.push_back(6193);

	// build fill reference
	for (const auto &fill : fills)
	{
		FillReference ref = { fill, fill };

		if (useExceptionList)
		{
			if (fill == 5946) ref = { 5950, 5950 };

			if (fill == 5952) ref = { 5962, 5958 };
			if (fill == 5954) ref = { 5962, 5958 };
			if (fill == 5958) ref = { 5962, 5958 };
			if (fill == 5960) ref = { 5962, 5962 };

			if (fill == 5966) ref = { 5971, 5966 };
			if (fill == 5974) ref = { 5976, 5974 };
			if (fill == 6055) ref = { 6055, 6057 };
			if (fill == 6086) ref = { 6089, 6089 };
			if (fill == 6176) ref = { 6176, 6177 };

			if (fill == 6193) ref = { 6193, 6192 };
		}

		fills_reference[fill] = ref;
	}
}

//----------------------------------------------------------------------------------------------------

void PrintFillRunMapping()
{
	for (const auto &p : fills_runs)
	{
		printf("fillInfoCollection.push_back(FillInfo(%u, false, %u, %u, \"fill %u\"));\n", p.first, p.second.front(), p.second.back(), p.first);
	}
}
