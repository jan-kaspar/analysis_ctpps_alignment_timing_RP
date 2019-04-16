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
	fills_runs[6230] = {303719, 303728, 303729};
	fills_runs[6236] = {303790, 303793, 303794, 303795};
	fills_runs[6238] = {303817, 303818, 303819};
	fills_runs[6239] = {303824, 303825};
	fills_runs[6240] = {303832};
	fills_runs[6241] = {303838};
	fills_runs[6243] = {303885};
	fills_runs[6245] = {303948, 303989};
	fills_runs[6247] = {303998, 303999, 304000};
	fills_runs[6252] = {304062};
	fills_runs[6253] = {304119, 304120, 304125};
	fills_runs[6255] = {304144};
	fills_runs[6258] = {304158};
	fills_runs[6259] = {304169, 304170};
	fills_runs[6261] = {304196, 304197, 304198, 304199, 304200};
	fills_runs[6262] = {304204};
	fills_runs[6263] = {304209};
	fills_runs[6266] = {304291, 304292};
	fills_runs[6268] = {304333};
	fills_runs[6269] = {304354};
	fills_runs[6271] = {304366};
	fills_runs[6272] = {304446, 304447, 304448, 304449, 304451, 304452};
	fills_runs[6275] = {304505, 304506, 304507, 304508};
	fills_runs[6276] = {304562};
	fills_runs[6278] = {304616};
	fills_runs[6279] = {304625, 304626};
	fills_runs[6283] = {304654, 304655};
	fills_runs[6284] = {304661, 304662, 304663};
	fills_runs[6285] = {304671, 304672};
	fills_runs[6287] = {304737, 304738, 304739, 304740};
	fills_runs[6288] = {304776, 304777, 304778};
	fills_runs[6291] = {304797};
	fills_runs[6294] = {304880};
	fills_runs[6295] = {304899, 304906, 304907};
	fills_runs[6297] = {305040, 305043, 305044, 305045, 305046};
	fills_runs[6298] = {305059, 305060, 305061, 305062, 305063, 305064};
	fills_runs[6300] = {305081};
	fills_runs[6303] = {305112, 305113, 305114};
	fills_runs[6304] = {305178, 305179, 305180, 305181, 305182, 305183, 305184, 305185, 305186, 305187, 305188};
	fills_runs[6305] = {305202, 305203, 305204};
	fills_runs[6306] = {305207, 305208};
	fills_runs[6307] = {305234, 305235, 305236, 305237};
	fills_runs[6308] = {305247, 305248, 305249, 305250, 305252};
	fills_runs[6309] = {305282};
	fills_runs[6311] = {305310, 305311, 305312, 305313, 305314};
	fills_runs[6312] = {305336, 305338, 305341, 305349, 305350, 305351};
	fills_runs[6313] = {305358};
	fills_runs[6314] = {305364, 305365, 305366, 305367};
	fills_runs[6315] = {305376, 305377};
	fills_runs[6317] = {305405, 305406};
	fills_runs[6318] = {305440, 305441};
	fills_runs[6323] = {305516, 305517, 305518};
	fills_runs[6324] = {305586, 305588, 305589, 305590};
	fills_runs[6325] = {305636};
	fills_runs[6336] = {305745, 305746, 305747, 305748, 305749, 305750, 305751, 305752, 305753, 305754, 305755, 305756, 305757, 305758};
	fills_runs[6337] = {305766};
	fills_runs[6341] = {305809};
	fills_runs[6343] = {305814};
	fills_runs[6344] = {305821};
	fills_runs[6346] = {305832, 305833, 305839, 305840, 305841, 305842};
	fills_runs[6347] = {305862};
	fills_runs[6348] = {305898};
	fills_runs[6349] = {305902};
	fills_runs[6351] = {305965, 305966, 305967};
	fills_runs[6355] = {306029, 306030};
	fills_runs[6356] = {306036, 306037, 306038, 306040, 306041, 306042, 306048, 306049, 306051};
	fills_runs[6358] = {306091, 306092, 306093, 306094, 306095, 306096};
	fills_runs[6360] = {306121, 306122, 306125, 306126};
	fills_runs[6362] = {306134, 306135, 306137, 306138, 306139};
	fills_runs[6364] = {306153, 306154, 306155, 306168, 306169, 306170, 306171};
	fills_runs[6370] = {306416, 306417, 306418, 306419, 306420, 306421, 306422, 306423, 306425, 306432};
	fills_runs[6371] = {306454, 306455, 306456, 306457, 306458, 306459, 306460, 306461, 306462};

	fills.push_back(6239);
	fills.push_back(6240);
	fills.push_back(6241);
	fills.push_back(6243);
	fills.push_back(6245);
	fills.push_back(6247);
	fills.push_back(6252);
	fills.push_back(6253);
	fills.push_back(6255);
	fills.push_back(6258);
	fills.push_back(6259);
	fills.push_back(6261);
	fills.push_back(6262);
	fills.push_back(6263);
	fills.push_back(6266);
	fills.push_back(6268);
	fills.push_back(6269);
	fills.push_back(6271);
	fills.push_back(6272);
	fills.push_back(6275);
	fills.push_back(6276);
	fills.push_back(6278);
	fills.push_back(6279);
	fills.push_back(6283);
	fills.push_back(6284);
	fills.push_back(6285);
	fills.push_back(6287);
	fills.push_back(6288);
	fills.push_back(6291);
	fills.push_back(6297);
	fills.push_back(6298);
	fills.push_back(6300);
	fills.push_back(6303);
	fills.push_back(6304);
	fills.push_back(6305);
	fills.push_back(6306);
	fills.push_back(6307);
	fills.push_back(6308);
	fills.push_back(6309);
	fills.push_back(6311);
	fills.push_back(6312);
	fills.push_back(6313);
	fills.push_back(6314);
	fills.push_back(6315);
	fills.push_back(6317);
	fills.push_back(6318);
	fills.push_back(6323);
	fills.push_back(6324);
	fills.push_back(6325);
	fills.push_back(6337);
	fills.push_back(6341);
	fills.push_back(6343);
	fills.push_back(6344);
	fills.push_back(6346);
	fills.push_back(6347);
	fills.push_back(6348);
	fills.push_back(6349);
	fills.push_back(6351);
	fills.push_back(6355);
	fills.push_back(6356);
	fills.push_back(6358);
	fills.push_back(6360);
	fills.push_back(6362);
	fills.push_back(6364);
	fills.push_back(6370);
	fills.push_back(6371);

	// build fill reference
	for (const auto &fill : fills)
	{
		FillReference ref = { fill, fill };

		if (useExceptionList)
		{
			if (fill >= 6239 && fill <= 6285) ref = { 6287, fill };
			if (fill == 6245) ref = { 6287, 6247 };
			if (fill == 6351) ref = { 6355, 6355 };
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
