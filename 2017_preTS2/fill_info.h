#ifndef _fill_info_h_
#define _fill_info_h_

#include <vector>
#include <string>

//----------------------------------------------------------------------------------------------------

struct FillInfo
{
	unsigned int fillNumber;
	bool margin;
	unsigned int runMin, runMax;
	std::string alignmentTag;

	FillInfo(unsigned int _fn=0, bool _m=false, unsigned int _rmin=0, unsigned int _rmax=0, const std::string &at="") :
		fillNumber(_fn), margin(_m), runMin(_rmin), runMax(_rmax), alignmentTag(at)
	{
	}
};

//----------------------------------------------------------------------------------------------------

struct FillInfoCollection : public std::vector<FillInfo> 
{
	unsigned int FindByFill(unsigned int fill, bool margin, FillInfo &fillInfo) const
	{
		for (const auto it : *this)
		{
			if (it.fillNumber == fill && it.margin == margin)
			{
				fillInfo = it;
				return 0;
			}
		}

		return 1;
	}

	unsigned int FindByRun(unsigned int run, FillInfo &fillInfo) const
	{
		for (const auto it : *this)
		{
			if (it.runMin <= run && it.runMax >= run)
			{
				fillInfo = it;
				return 0;
			}
		}

		return 1;
	}
};

//----------------------------------------------------------------------------------------------------

FillInfoCollection fillInfoCollection;

//----------------------------------------------------------------------------------------------------

void InitFillInfoCollection2016()
{
	// 2016 pre-TS2
	fillInfoCollection.push_back(FillInfo(4947, true, 273725, 273730, "phys_margin/fill_4947"));
	fillInfoCollection.push_back(FillInfo(4953, true, 274094, 274094, "phys_margin/fill_4953"));
	fillInfoCollection.push_back(FillInfo(4961, true, 274198, 274200, "phys_margin/fill_4961"));
	fillInfoCollection.push_back(FillInfo(4964, true, 274240, 274241, "phys_margin/fill_4964"));
	fillInfoCollection.push_back(FillInfo(4964, false, 274244, 274244, "phys_no_margin/fill_4964"));
	fillInfoCollection.push_back(FillInfo(4976, true, 274282, 274286, "phys_margin/fill_4976"));
	fillInfoCollection.push_back(FillInfo(4985, false, 274387, 274388, "phys_no_margin/fill_4985"));
	fillInfoCollection.push_back(FillInfo(4988, false, 274420, 274422, "phys_no_margin/fill_4988"));
	fillInfoCollection.push_back(FillInfo(4990, false, 274440, 274443, "phys_no_margin/fill_4990"));
	fillInfoCollection.push_back(FillInfo(5005, false, 274954, 274959, "phys_no_margin/fill_5005"));
	fillInfoCollection.push_back(FillInfo(5013, false, 274966, 274971, "phys_no_margin/fill_5013"));
	fillInfoCollection.push_back(FillInfo(5017, false, 274998, 275001, "phys_no_margin/fill_5017"));
	fillInfoCollection.push_back(FillInfo(5020, false, 275059, 275074, "phys_no_margin/fill_5020"));
	fillInfoCollection.push_back(FillInfo(5021, false, 275124, 275125, "phys_no_margin/fill_5021"));
	fillInfoCollection.push_back(FillInfo(5024, false, 275282, 275293, "phys_no_margin/fill_5024"));
	fillInfoCollection.push_back(FillInfo(5026, false, 275309, 275311, "phys_no_margin/fill_5026"));
	fillInfoCollection.push_back(FillInfo(5027, false, 275319, 275338, "phys_no_margin/fill_5027"));
	fillInfoCollection.push_back(FillInfo(5028, false, 275344, 275345, "phys_no_margin/fill_5028"));
	fillInfoCollection.push_back(FillInfo(5029, false, 275370, 275371, "phys_no_margin/fill_5029"));
	fillInfoCollection.push_back(FillInfo(5030, false, 275375, 275376, "phys_no_margin/fill_5030"));
	fillInfoCollection.push_back(FillInfo(5038, false, 275656, 275659, "phys_no_margin/fill_5038"));
	fillInfoCollection.push_back(FillInfo(5043, false, 275757, 275783, "phys_no_margin/fill_5043"));
	fillInfoCollection.push_back(FillInfo(5045, false, 275828, 275847, "phys_no_margin/fill_5045"));
	fillInfoCollection.push_back(FillInfo(5048, false, 275886, 275890, "phys_no_margin/fill_5048"));
	fillInfoCollection.push_back(FillInfo(5052, false, 275911, 275931, "phys_no_margin/fill_5052"));

	fillInfoCollection.push_back(FillInfo(5261, false, 279760, 279767, "phys_no_margin/fill_5261"));
	fillInfoCollection.push_back(FillInfo(5264, false, 279794, 279794, "phys_no_margin/fill_5264"));
	fillInfoCollection.push_back(FillInfo(5265, false, 279823, 279823, "phys_no_margin/fill_5265"));
	fillInfoCollection.push_back(FillInfo(5266, false, 279841, 279841, "phys_no_margin/fill_5266"));
	fillInfoCollection.push_back(FillInfo(5267, false, 279844, 279865, "phys_no_margin/fill_5267"));
	fillInfoCollection.push_back(FillInfo(5274, false, 279931, 279931, "phys_no_margin/fill_5274"));
	fillInfoCollection.push_back(FillInfo(5275, false, 279966, 279966, "phys_no_margin/fill_5275"));
	fillInfoCollection.push_back(FillInfo(5276, false, 279975, 279975, "phys_no_margin/fill_5276"));
	fillInfoCollection.push_back(FillInfo(5277, false, 279993, 280024, "phys_no_margin/fill_5277"));
	fillInfoCollection.push_back(FillInfo(5279, false, 280187, 280194, "phys_no_margin/fill_5279"));
	fillInfoCollection.push_back(FillInfo(5287, false, 280327, 280364, "phys_no_margin/fill_5287"));
	fillInfoCollection.push_back(FillInfo(5288, false, 280383, 280385, "phys_no_margin/fill_5288"));
}

void InitFillInfoCollection2017()
{
	// 2017 pre-TS2
	fillInfoCollection.push_back(FillInfo(5839, false, 297046, 297050, "fill 5839"));
	fillInfoCollection.push_back(FillInfo(5840, false, 297056, 297057, "fill 5840"));
	fillInfoCollection.push_back(FillInfo(5842, false, 297099, 297101, "fill 5842"));
	fillInfoCollection.push_back(FillInfo(5845, false, 297113, 297114, "fill 5845"));
	fillInfoCollection.push_back(FillInfo(5848, false, 297168, 297182, "fill 5848"));
	fillInfoCollection.push_back(FillInfo(5849, false, 297211, 297229, "fill 5849"));
	fillInfoCollection.push_back(FillInfo(5856, false, 297281, 297316, "fill 5856"));
	fillInfoCollection.push_back(FillInfo(5862, false, 297359, 297359, "fill 5862"));
	fillInfoCollection.push_back(FillInfo(5864, false, 297411, 297411, "fill 5864"));
	fillInfoCollection.push_back(FillInfo(5865, false, 297424, 297435, "fill 5865"));
	fillInfoCollection.push_back(FillInfo(5868, false, 297467, 297469, "fill 5868"));
	fillInfoCollection.push_back(FillInfo(5870, false, 297474, 297474, "fill 5870"));
	fillInfoCollection.push_back(FillInfo(5872, false, 297483, 297488, "fill 5872"));
	fillInfoCollection.push_back(FillInfo(5873, false, 297494, 297505, "fill 5873"));
	fillInfoCollection.push_back(FillInfo(5876, false, 297557, 297563, "fill 5876"));
	fillInfoCollection.push_back(FillInfo(5878, false, 297598, 297606, "fill 5878"));
	fillInfoCollection.push_back(FillInfo(5880, false, 297620, 297620, "fill 5880"));
	fillInfoCollection.push_back(FillInfo(5882, false, 297656, 297666, "fill 5882"));
	fillInfoCollection.push_back(FillInfo(5883, false, 297670, 297678, "fill 5883"));
	fillInfoCollection.push_back(FillInfo(5885, false, 297713, 297715, "fill 5885"));
	fillInfoCollection.push_back(FillInfo(5887, false, 297722, 297723, "fill 5887"));
	fillInfoCollection.push_back(FillInfo(5919, false, 298653, 298653, "fill 5919"));
	fillInfoCollection.push_back(FillInfo(5920, false, 298673, 298681, "fill 5920"));
	fillInfoCollection.push_back(FillInfo(5930, false, 298809, 298809, "fill 5930"));
	fillInfoCollection.push_back(FillInfo(5934, false, 298853, 298855, "fill 5934"));
	fillInfoCollection.push_back(FillInfo(5942, false, 298996, 299000, "fill 5942"));
	fillInfoCollection.push_back(FillInfo(5946, false, 299042, 299042, "fill 5946"));
	fillInfoCollection.push_back(FillInfo(5950, false, 299061, 299067, "fill 5950"));
	fillInfoCollection.push_back(FillInfo(5952, false, 299096, 299096, "fill 5952"));
	fillInfoCollection.push_back(FillInfo(5954, false, 299149, 299149, "fill 5954"));
	fillInfoCollection.push_back(FillInfo(5958, false, 299178, 299185, "fill 5958"));
	fillInfoCollection.push_back(FillInfo(5960, false, 299316, 299329, "fill 5960"));
	fillInfoCollection.push_back(FillInfo(5962, false, 299368, 299370, "fill 5962"));
	fillInfoCollection.push_back(FillInfo(5963, false, 299380, 299381, "fill 5963"));
	fillInfoCollection.push_back(FillInfo(5965, false, 299393, 299396, "fill 5965"));
	fillInfoCollection.push_back(FillInfo(5966, false, 299420, 299420, "fill 5966"));
	fillInfoCollection.push_back(FillInfo(5971, false, 299443, 299443, "fill 5971"));
	fillInfoCollection.push_back(FillInfo(5974, false, 299450, 299450, "fill 5974"));
	fillInfoCollection.push_back(FillInfo(5976, false, 299477, 299481, "fill 5976"));
	fillInfoCollection.push_back(FillInfo(5979, false, 299592, 299598, "fill 5979"));
	fillInfoCollection.push_back(FillInfo(5980, false, 299614, 299617, "fill 5980"));
	fillInfoCollection.push_back(FillInfo(5984, false, 299649, 299650, "fill 5984"));
	fillInfoCollection.push_back(FillInfo(6012, false, 299996, 299996, "fill 6012"));
	fillInfoCollection.push_back(FillInfo(6015, false, 300007, 300007, "fill 6015"));
	fillInfoCollection.push_back(FillInfo(6016, false, 300015, 300050, "fill 6016"));
	fillInfoCollection.push_back(FillInfo(6018, false, 300079, 300079, "fill 6018"));
	fillInfoCollection.push_back(FillInfo(6019, false, 300087, 300088, "fill 6019"));
	fillInfoCollection.push_back(FillInfo(6020, false, 300104, 300107, "fill 6020"));
	fillInfoCollection.push_back(FillInfo(6021, false, 300117, 300117, "fill 6021"));
	fillInfoCollection.push_back(FillInfo(6024, false, 300122, 300124, "fill 6024"));
	fillInfoCollection.push_back(FillInfo(6026, false, 300155, 300157, "fill 6026"));
	fillInfoCollection.push_back(FillInfo(6030, false, 300226, 300226, "fill 6030"));
	fillInfoCollection.push_back(FillInfo(6031, false, 300233, 300241, "fill 6031"));
	fillInfoCollection.push_back(FillInfo(6035, false, 300280, 300284, "fill 6035"));
	fillInfoCollection.push_back(FillInfo(6041, false, 300364, 300375, "fill 6041"));
	fillInfoCollection.push_back(FillInfo(6044, false, 300389, 300401, "fill 6044"));
	fillInfoCollection.push_back(FillInfo(6046, false, 300459, 300467, "fill 6046"));
	fillInfoCollection.push_back(FillInfo(6048, false, 300497, 300500, "fill 6048"));
	fillInfoCollection.push_back(FillInfo(6050, false, 300514, 300517, "fill 6050"));
	fillInfoCollection.push_back(FillInfo(6052, false, 300538, 300561, "fill 6052"));
	fillInfoCollection.push_back(FillInfo(6053, false, 300574, 300576, "fill 6053"));
	fillInfoCollection.push_back(FillInfo(6054, false, 300631, 300636, "fill 6054"));
	fillInfoCollection.push_back(FillInfo(6055, false, 300673, 300676, "fill 6055"));
	fillInfoCollection.push_back(FillInfo(6057, false, 300742, 300742, "fill 6057"));
	fillInfoCollection.push_back(FillInfo(6060, false, 300777, 300785, "fill 6060"));
	fillInfoCollection.push_back(FillInfo(6061, false, 300806, 300817, "fill 6061"));
	fillInfoCollection.push_back(FillInfo(6072, false, 301046, 301046, "fill 6072"));
	fillInfoCollection.push_back(FillInfo(6079, false, 301086, 301088, "fill 6079"));
	fillInfoCollection.push_back(FillInfo(6082, false, 301141, 301142, "fill 6082"));
	fillInfoCollection.push_back(FillInfo(6084, false, 301161, 301165, "fill 6084"));
	fillInfoCollection.push_back(FillInfo(6086, false, 301179, 301183, "fill 6086"));
	fillInfoCollection.push_back(FillInfo(6089, false, 301281, 301283, "fill 6089"));
	fillInfoCollection.push_back(FillInfo(6090, false, 301298, 301298, "fill 6090"));
	fillInfoCollection.push_back(FillInfo(6091, false, 301323, 301323, "fill 6091"));
	fillInfoCollection.push_back(FillInfo(6093, false, 301330, 301330, "fill 6093"));
	fillInfoCollection.push_back(FillInfo(6094, false, 301359, 301359, "fill 6094"));
	fillInfoCollection.push_back(FillInfo(6096, false, 301383, 301384, "fill 6096"));
	fillInfoCollection.push_back(FillInfo(6097, false, 301391, 301399, "fill 6097"));
	fillInfoCollection.push_back(FillInfo(6098, false, 301417, 301417, "fill 6098"));
	fillInfoCollection.push_back(FillInfo(6104, false, 301447, 301450, "fill 6104"));
	fillInfoCollection.push_back(FillInfo(6105, false, 301461, 301461, "fill 6105"));
	fillInfoCollection.push_back(FillInfo(6106, false, 301472, 301480, "fill 6106"));
	fillInfoCollection.push_back(FillInfo(6110, false, 301519, 301532, "fill 6110"));
	fillInfoCollection.push_back(FillInfo(6114, false, 301567, 301567, "fill 6114"));
	fillInfoCollection.push_back(FillInfo(6116, false, 301627, 301627, "fill 6116"));
	fillInfoCollection.push_back(FillInfo(6119, false, 301664, 301665, "fill 6119"));
	fillInfoCollection.push_back(FillInfo(6123, false, 301694, 301694, "fill 6123"));
	fillInfoCollection.push_back(FillInfo(6136, false, 301912, 301914, "fill 6136"));
	fillInfoCollection.push_back(FillInfo(6138, false, 301941, 301941, "fill 6138"));
	fillInfoCollection.push_back(FillInfo(6140, false, 301959, 301960, "fill 6140"));
	fillInfoCollection.push_back(FillInfo(6141, false, 301969, 301970, "fill 6141"));
	fillInfoCollection.push_back(FillInfo(6142, false, 301984, 301987, "fill 6142"));
	fillInfoCollection.push_back(FillInfo(6143, false, 301997, 301998, "fill 6143"));
	fillInfoCollection.push_back(FillInfo(6146, false, 302019, 302019, "fill 6146"));
	fillInfoCollection.push_back(FillInfo(6147, false, 302026, 302044, "fill 6147"));
	fillInfoCollection.push_back(FillInfo(6152, false, 302131, 302132, "fill 6152"));
	fillInfoCollection.push_back(FillInfo(6155, false, 302159, 302159, "fill 6155"));
	fillInfoCollection.push_back(FillInfo(6156, false, 302163, 302166, "fill 6156"));
	fillInfoCollection.push_back(FillInfo(6158, false, 302225, 302225, "fill 6158"));
	fillInfoCollection.push_back(FillInfo(6159, false, 302228, 302229, "fill 6159"));
	fillInfoCollection.push_back(FillInfo(6160, false, 302239, 302240, "fill 6160"));
	fillInfoCollection.push_back(FillInfo(6161, false, 302262, 302263, "fill 6161"));
	fillInfoCollection.push_back(FillInfo(6165, false, 302277, 302280, "fill 6165"));
	fillInfoCollection.push_back(FillInfo(6167, false, 302322, 302322, "fill 6167"));
	fillInfoCollection.push_back(FillInfo(6168, false, 302328, 302328, "fill 6168"));
	fillInfoCollection.push_back(FillInfo(6169, false, 302337, 302350, "fill 6169"));
	fillInfoCollection.push_back(FillInfo(6170, false, 302388, 302388, "fill 6170"));
	fillInfoCollection.push_back(FillInfo(6171, false, 302392, 302393, "fill 6171"));
	fillInfoCollection.push_back(FillInfo(6174, false, 302448, 302448, "fill 6174"));
	fillInfoCollection.push_back(FillInfo(6175, false, 302472, 302476, "fill 6175"));
	fillInfoCollection.push_back(FillInfo(6176, false, 302479, 302479, "fill 6176"));
	fillInfoCollection.push_back(FillInfo(6177, false, 302484, 302494, "fill 6177"));
	fillInfoCollection.push_back(FillInfo(6179, false, 302509, 302509, "fill 6179"));
	fillInfoCollection.push_back(FillInfo(6180, false, 302513, 302513, "fill 6180"));
	fillInfoCollection.push_back(FillInfo(6182, false, 302522, 302526, "fill 6182"));
	fillInfoCollection.push_back(FillInfo(6185, false, 302548, 302555, "fill 6185"));
	fillInfoCollection.push_back(FillInfo(6186, false, 302563, 302573, "fill 6186"));
	fillInfoCollection.push_back(FillInfo(6189, false, 302596, 302597, "fill 6189"));
	fillInfoCollection.push_back(FillInfo(6191, false, 302634, 302635, "fill 6191"));
	fillInfoCollection.push_back(FillInfo(6192, false, 302646, 302654, "fill 6192"));
	fillInfoCollection.push_back(FillInfo(6193, false, 302660, 302663, "fill 6193"));

	// 2017 post-TS2
	fillInfoCollection.push_back(FillInfo(6230, false, 303719, 303729, "fill 6230"));
	fillInfoCollection.push_back(FillInfo(6236, false, 303790, 303795, "fill 6236"));
	fillInfoCollection.push_back(FillInfo(6238, false, 303817, 303819, "fill 6238"));
	fillInfoCollection.push_back(FillInfo(6239, false, 303824, 303825, "fill 6239"));
	fillInfoCollection.push_back(FillInfo(6240, false, 303832, 303832, "fill 6240"));
	fillInfoCollection.push_back(FillInfo(6241, false, 303838, 303838, "fill 6241"));
	fillInfoCollection.push_back(FillInfo(6243, false, 303885, 303885, "fill 6243"));
	fillInfoCollection.push_back(FillInfo(6245, false, 303948, 303989, "fill 6245"));
	fillInfoCollection.push_back(FillInfo(6247, false, 303998, 304000, "fill 6247"));
	fillInfoCollection.push_back(FillInfo(6252, false, 304062, 304062, "fill 6252"));
	fillInfoCollection.push_back(FillInfo(6253, false, 304119, 304125, "fill 6253"));
	fillInfoCollection.push_back(FillInfo(6255, false, 304144, 304144, "fill 6255"));
	fillInfoCollection.push_back(FillInfo(6258, false, 304158, 304158, "fill 6258"));
	fillInfoCollection.push_back(FillInfo(6259, false, 304169, 304170, "fill 6259"));
	fillInfoCollection.push_back(FillInfo(6261, false, 304196, 304200, "fill 6261"));
	fillInfoCollection.push_back(FillInfo(6262, false, 304204, 304204, "fill 6262"));
	fillInfoCollection.push_back(FillInfo(6263, false, 304209, 304209, "fill 6263"));
	fillInfoCollection.push_back(FillInfo(6266, false, 304291, 304292, "fill 6266"));
	fillInfoCollection.push_back(FillInfo(6268, false, 304333, 304333, "fill 6268"));
	fillInfoCollection.push_back(FillInfo(6269, false, 304354, 304354, "fill 6269"));
	fillInfoCollection.push_back(FillInfo(6271, false, 304366, 304366, "fill 6271"));
	fillInfoCollection.push_back(FillInfo(6272, false, 304446, 304452, "fill 6272"));
	fillInfoCollection.push_back(FillInfo(6275, false, 304505, 304508, "fill 6275"));
	fillInfoCollection.push_back(FillInfo(6276, false, 304562, 304562, "fill 6276"));
	fillInfoCollection.push_back(FillInfo(6278, false, 304616, 304616, "fill 6278"));
	fillInfoCollection.push_back(FillInfo(6279, false, 304625, 304626, "fill 6279"));
	fillInfoCollection.push_back(FillInfo(6283, false, 304654, 304655, "fill 6283"));
	fillInfoCollection.push_back(FillInfo(6284, false, 304661, 304663, "fill 6284"));
	fillInfoCollection.push_back(FillInfo(6285, false, 304671, 304672, "fill 6285"));
	fillInfoCollection.push_back(FillInfo(6287, false, 304737, 304740, "fill 6287"));
	fillInfoCollection.push_back(FillInfo(6288, false, 304776, 304778, "fill 6288"));
	fillInfoCollection.push_back(FillInfo(6291, false, 304797, 304797, "fill 6291"));
	fillInfoCollection.push_back(FillInfo(6294, false, 304880, 304880, "fill 6294"));
	fillInfoCollection.push_back(FillInfo(6295, false, 304899, 304907, "fill 6295"));
	fillInfoCollection.push_back(FillInfo(6297, false, 305040, 305046, "fill 6297"));
	fillInfoCollection.push_back(FillInfo(6298, false, 305059, 305064, "fill 6298"));
	fillInfoCollection.push_back(FillInfo(6300, false, 305081, 305081, "fill 6300"));
	fillInfoCollection.push_back(FillInfo(6303, false, 305112, 305114, "fill 6303"));
	fillInfoCollection.push_back(FillInfo(6304, false, 305178, 305188, "fill 6304"));
	fillInfoCollection.push_back(FillInfo(6305, false, 305202, 305204, "fill 6305"));
	fillInfoCollection.push_back(FillInfo(6306, false, 305207, 305208, "fill 6306"));
	fillInfoCollection.push_back(FillInfo(6307, false, 305234, 305237, "fill 6307"));
	fillInfoCollection.push_back(FillInfo(6308, false, 305247, 305252, "fill 6308"));
	fillInfoCollection.push_back(FillInfo(6309, false, 305282, 305282, "fill 6309"));
	fillInfoCollection.push_back(FillInfo(6311, false, 305310, 305314, "fill 6311"));
	fillInfoCollection.push_back(FillInfo(6312, false, 305336, 305351, "fill 6312"));
	fillInfoCollection.push_back(FillInfo(6313, false, 305358, 305358, "fill 6313"));
	fillInfoCollection.push_back(FillInfo(6314, false, 305364, 305367, "fill 6314"));
	fillInfoCollection.push_back(FillInfo(6315, false, 305376, 305377, "fill 6315"));
	fillInfoCollection.push_back(FillInfo(6317, false, 305405, 305406, "fill 6317"));
	fillInfoCollection.push_back(FillInfo(6318, false, 305440, 305441, "fill 6318"));
	fillInfoCollection.push_back(FillInfo(6323, false, 305516, 305518, "fill 6323"));
	fillInfoCollection.push_back(FillInfo(6324, false, 305586, 305590, "fill 6324"));
	fillInfoCollection.push_back(FillInfo(6325, false, 305636, 305636, "fill 6325"));
	fillInfoCollection.push_back(FillInfo(6336, false, 305745, 305758, "fill 6336"));
	fillInfoCollection.push_back(FillInfo(6337, false, 305766, 305766, "fill 6337"));
	fillInfoCollection.push_back(FillInfo(6341, false, 305809, 305809, "fill 6341"));
	fillInfoCollection.push_back(FillInfo(6343, false, 305814, 305814, "fill 6343"));
	fillInfoCollection.push_back(FillInfo(6344, false, 305821, 305821, "fill 6344"));
	fillInfoCollection.push_back(FillInfo(6346, false, 305832, 305842, "fill 6346"));
	fillInfoCollection.push_back(FillInfo(6347, false, 305862, 305862, "fill 6347"));
	fillInfoCollection.push_back(FillInfo(6348, false, 305898, 305898, "fill 6348"));
	fillInfoCollection.push_back(FillInfo(6349, false, 305902, 305902, "fill 6349"));
	fillInfoCollection.push_back(FillInfo(6351, false, 305965, 305967, "fill 6351"));
	fillInfoCollection.push_back(FillInfo(6355, false, 306029, 306030, "fill 6355"));
	fillInfoCollection.push_back(FillInfo(6356, false, 306036, 306051, "fill 6356"));
	fillInfoCollection.push_back(FillInfo(6358, false, 306091, 306096, "fill 6358"));
	fillInfoCollection.push_back(FillInfo(6360, false, 306121, 306126, "fill 6360"));
	fillInfoCollection.push_back(FillInfo(6362, false, 306134, 306139, "fill 6362"));
	fillInfoCollection.push_back(FillInfo(6364, false, 306153, 306171, "fill 6364"));
	fillInfoCollection.push_back(FillInfo(6370, false, 306416, 306432, "fill 6370"));
	fillInfoCollection.push_back(FillInfo(6371, false, 306454, 306462, "fill 6371"));
}

void InitFillInfoCollection2018()
{
	// 2018
	fillInfoCollection.push_back(FillInfo(6579, false, 314747, 314764, "fill 6579"));
	fillInfoCollection.push_back(FillInfo(6583, false, 314810, 314811, "fill 6583"));
	fillInfoCollection.push_back(FillInfo(6584, false, 314816, 314816, "fill 6584"));
	fillInfoCollection.push_back(FillInfo(6592, false, 314848, 314848, "fill 6592"));
	fillInfoCollection.push_back(FillInfo(6594, false, 314859, 314878, "fill 6594"));
	fillInfoCollection.push_back(FillInfo(6595, false, 314890, 314890, "fill 6595"));
	fillInfoCollection.push_back(FillInfo(6611, false, 315104, 315112, "fill 6611"));
	fillInfoCollection.push_back(FillInfo(6612, false, 315150, 315172, "fill 6612"));
	fillInfoCollection.push_back(FillInfo(6613, false, 315179, 315180, "fill 6613"));
	fillInfoCollection.push_back(FillInfo(6614, false, 315187, 315190, "fill 6614"));
	fillInfoCollection.push_back(FillInfo(6615, false, 315242, 315259, "fill 6615"));
	fillInfoCollection.push_back(FillInfo(6616, false, 315264, 315273, "fill 6616"));
	fillInfoCollection.push_back(FillInfo(6617, false, 315322, 315322, "fill 6617"));
	fillInfoCollection.push_back(FillInfo(6618, false, 315339, 315339, "fill 6618"));
	fillInfoCollection.push_back(FillInfo(6620, false, 315357, 315357, "fill 6620"));
	fillInfoCollection.push_back(FillInfo(6621, false, 315361, 315366, "fill 6621"));
	fillInfoCollection.push_back(FillInfo(6624, false, 315420, 315420, "fill 6624"));
	fillInfoCollection.push_back(FillInfo(6628, false, 315488, 315490, "fill 6628"));
	fillInfoCollection.push_back(FillInfo(6629, false, 315506, 315512, "fill 6629"));
	fillInfoCollection.push_back(FillInfo(6633, false, 315543, 315543, "fill 6633"));
	fillInfoCollection.push_back(FillInfo(6636, false, 315555, 315557, "fill 6636"));
	fillInfoCollection.push_back(FillInfo(6638, false, 315640, 315648, "fill 6638"));
	fillInfoCollection.push_back(FillInfo(6639, false, 315689, 315690, "fill 6639"));
	fillInfoCollection.push_back(FillInfo(6640, false, 315702, 315705, "fill 6640"));
	fillInfoCollection.push_back(FillInfo(6641, false, 315713, 315713, "fill 6641"));
	fillInfoCollection.push_back(FillInfo(6642, false, 315721, 315721, "fill 6642"));
	fillInfoCollection.push_back(FillInfo(6643, false, 315741, 315741, "fill 6643"));
	fillInfoCollection.push_back(FillInfo(6645, false, 315764, 315764, "fill 6645"));
	fillInfoCollection.push_back(FillInfo(6646, false, 315770, 315770, "fill 6646"));
	fillInfoCollection.push_back(FillInfo(6648, false, 315784, 315790, "fill 6648"));
	fillInfoCollection.push_back(FillInfo(6650, false, 315800, 315801, "fill 6650"));
	fillInfoCollection.push_back(FillInfo(6654, false, 315840, 315840, "fill 6654"));
	fillInfoCollection.push_back(FillInfo(6659, false, 315973, 315974, "fill 6659"));
	fillInfoCollection.push_back(FillInfo(6662, false, 316058, 316062, "fill 6662"));
	fillInfoCollection.push_back(FillInfo(6663, false, 316082, 316082, "fill 6663"));
	fillInfoCollection.push_back(FillInfo(6666, false, 316109, 316114, "fill 6666"));
	fillInfoCollection.push_back(FillInfo(6672, false, 316151, 316153, "fill 6672"));
	fillInfoCollection.push_back(FillInfo(6674, false, 316186, 316187, "fill 6674"));
	fillInfoCollection.push_back(FillInfo(6675, false, 316199, 316202, "fill 6675"));
	fillInfoCollection.push_back(FillInfo(6677, false, 316216, 316219, "fill 6677"));
	fillInfoCollection.push_back(FillInfo(6681, false, 316239, 316241, "fill 6681"));
	fillInfoCollection.push_back(FillInfo(6683, false, 316271, 316271, "fill 6683"));
	fillInfoCollection.push_back(FillInfo(6688, false, 316361, 316363, "fill 6688"));
	fillInfoCollection.push_back(FillInfo(6690, false, 316377, 316380, "fill 6690"));
	fillInfoCollection.push_back(FillInfo(6692, false, 316441, 316441, "fill 6692"));
	fillInfoCollection.push_back(FillInfo(6693, false, 316455, 316457, "fill 6693"));
	fillInfoCollection.push_back(FillInfo(6694, false, 316469, 316472, "fill 6694"));
	fillInfoCollection.push_back(FillInfo(6696, false, 316505, 316505, "fill 6696"));
	fillInfoCollection.push_back(FillInfo(6699, false, 316559, 316559, "fill 6699"));
	fillInfoCollection.push_back(FillInfo(6700, false, 316569, 316569, "fill 6700"));
	fillInfoCollection.push_back(FillInfo(6702, false, 316590, 316590, "fill 6702"));
	fillInfoCollection.push_back(FillInfo(6706, false, 316613, 316615, "fill 6706"));
	fillInfoCollection.push_back(FillInfo(6709, false, 316664, 316667, "fill 6709"));
	fillInfoCollection.push_back(FillInfo(6710, false, 316700, 316702, "fill 6710"));
	fillInfoCollection.push_back(FillInfo(6711, false, 316715, 316723, "fill 6711"));
	fillInfoCollection.push_back(FillInfo(6712, false, 316758, 316758, "fill 6712"));
	fillInfoCollection.push_back(FillInfo(6714, false, 316766, 316766, "fill 6714"));
	fillInfoCollection.push_back(FillInfo(6719, false, 316876, 316879, "fill 6719"));
	fillInfoCollection.push_back(FillInfo(6724, false, 316928, 316928, "fill 6724"));
	fillInfoCollection.push_back(FillInfo(6729, false, 316944, 316944, "fill 6729"));
	fillInfoCollection.push_back(FillInfo(6731, false, 316985, 316985, "fill 6731"));
	fillInfoCollection.push_back(FillInfo(6733, false, 316993, 316995, "fill 6733"));
	fillInfoCollection.push_back(FillInfo(6737, false, 317080, 317080, "fill 6737"));
	fillInfoCollection.push_back(FillInfo(6738, false, 317087, 317089, "fill 6738"));
	fillInfoCollection.push_back(FillInfo(6740, false, 317170, 317170, "fill 6740"));
	fillInfoCollection.push_back(FillInfo(6741, false, 317182, 317182, "fill 6741"));
	fillInfoCollection.push_back(FillInfo(6744, false, 317212, 317213, "fill 6744"));
	fillInfoCollection.push_back(FillInfo(6747, false, 317279, 317279, "fill 6747"));
	fillInfoCollection.push_back(FillInfo(6749, false, 317291, 317297, "fill 6749"));
	fillInfoCollection.push_back(FillInfo(6751, false, 317319, 317320, "fill 6751"));
	fillInfoCollection.push_back(FillInfo(6752, false, 317338, 317340, "fill 6752"));
	fillInfoCollection.push_back(FillInfo(6755, false, 317382, 317383, "fill 6755"));
	fillInfoCollection.push_back(FillInfo(6757, false, 317391, 317392, "fill 6757"));
	fillInfoCollection.push_back(FillInfo(6759, false, 317434, 317438, "fill 6759"));
	fillInfoCollection.push_back(FillInfo(6761, false, 317475, 317488, "fill 6761"));
	fillInfoCollection.push_back(FillInfo(6762, false, 317509, 317512, "fill 6762"));
	fillInfoCollection.push_back(FillInfo(6763, false, 317527, 317527, "fill 6763"));
	fillInfoCollection.push_back(FillInfo(6768, false, 317591, 317591, "fill 6768"));
	fillInfoCollection.push_back(FillInfo(6770, false, 317626, 317626, "fill 6770"));
	fillInfoCollection.push_back(FillInfo(6772, false, 317640, 317641, "fill 6772"));
	fillInfoCollection.push_back(FillInfo(6773, false, 317648, 317650, "fill 6773"));
	fillInfoCollection.push_back(FillInfo(6774, false, 317661, 317663, "fill 6774"));
	fillInfoCollection.push_back(FillInfo(6776, false, 317683, 317683, "fill 6776"));
	fillInfoCollection.push_back(FillInfo(6778, false, 317696, 317696, "fill 6778"));
	fillInfoCollection.push_back(FillInfo(6843, false, 318622, 318622, "fill 6843"));
	fillInfoCollection.push_back(FillInfo(6847, false, 318653, 318675, "fill 6847"));
	fillInfoCollection.push_back(FillInfo(6850, false, 318712, 318734, "fill 6850"));
	fillInfoCollection.push_back(FillInfo(6854, false, 318816, 318820, "fill 6854"));
	fillInfoCollection.push_back(FillInfo(6858, false, 318828, 318828, "fill 6858"));
	fillInfoCollection.push_back(FillInfo(6860, false, 318872, 318877, "fill 6860"));
	fillInfoCollection.push_back(FillInfo(6864, false, 318939, 318953, "fill 6864"));
	fillInfoCollection.push_back(FillInfo(6868, false, 318980, 319019, "fill 6868"));
	fillInfoCollection.push_back(FillInfo(6874, false, 319077, 319077, "fill 6874"));
	fillInfoCollection.push_back(FillInfo(6877, false, 319097, 319104, "fill 6877"));
	fillInfoCollection.push_back(FillInfo(6879, false, 319124, 319125, "fill 6879"));
	fillInfoCollection.push_back(FillInfo(6881, false, 319159, 319160, "fill 6881"));
	fillInfoCollection.push_back(FillInfo(6882, false, 319173, 319177, "fill 6882"));
	fillInfoCollection.push_back(FillInfo(6884, false, 319189, 319190, "fill 6884"));
	fillInfoCollection.push_back(FillInfo(6885, false, 319222, 319223, "fill 6885"));
	fillInfoCollection.push_back(FillInfo(6890, false, 319254, 319274, "fill 6890"));
	fillInfoCollection.push_back(FillInfo(6891, false, 319300, 319300, "fill 6891"));
	fillInfoCollection.push_back(FillInfo(6892, false, 319310, 319311, "fill 6892"));
	fillInfoCollection.push_back(FillInfo(6901, false, 319337, 319337, "fill 6901"));
	fillInfoCollection.push_back(FillInfo(6904, false, 319347, 319349, "fill 6904"));
	fillInfoCollection.push_back(FillInfo(6909, false, 319449, 319472, "fill 6909"));
	fillInfoCollection.push_back(FillInfo(6911, false, 319486, 319503, "fill 6911"));
	fillInfoCollection.push_back(FillInfo(6912, false, 319524, 319528, "fill 6912"));
	fillInfoCollection.push_back(FillInfo(6913, false, 319554, 319559, "fill 6913"));
	fillInfoCollection.push_back(FillInfo(6919, false, 319579, 319579, "fill 6919"));
	fillInfoCollection.push_back(FillInfo(6921, false, 319625, 319625, "fill 6921"));
	fillInfoCollection.push_back(FillInfo(6923, false, 319639, 319639, "fill 6923"));
	fillInfoCollection.push_back(FillInfo(6924, false, 319656, 319659, "fill 6924"));
	fillInfoCollection.push_back(FillInfo(6925, false, 319678, 319678, "fill 6925"));
	fillInfoCollection.push_back(FillInfo(6927, false, 319687, 319687, "fill 6927"));
	fillInfoCollection.push_back(FillInfo(6929, false, 319697, 319698, "fill 6929"));
	fillInfoCollection.push_back(FillInfo(6931, false, 319756, 319756, "fill 6931"));
	fillInfoCollection.push_back(FillInfo(6939, false, 319840, 319841, "fill 6939"));
	fillInfoCollection.push_back(FillInfo(6940, false, 319847, 319854, "fill 6940"));
	fillInfoCollection.push_back(FillInfo(6942, false, 319908, 319915, "fill 6942"));
	fillInfoCollection.push_back(FillInfo(6944, false, 319941, 319942, "fill 6944"));
	fillInfoCollection.push_back(FillInfo(6946, false, 319950, 319950, "fill 6946"));
	fillInfoCollection.push_back(FillInfo(6953, false, 319991, 319993, "fill 6953"));
	fillInfoCollection.push_back(FillInfo(6956, false, 320002, 320012, "fill 6956"));
	fillInfoCollection.push_back(FillInfo(6957, false, 320023, 320026, "fill 6957"));
	fillInfoCollection.push_back(FillInfo(6960, false, 320038, 320040, "fill 6960"));
	fillInfoCollection.push_back(FillInfo(6961, false, 320058, 320065, "fill 6961"));
	fillInfoCollection.push_back(FillInfo(6966, false, 320137, 320137, "fill 6966"));
	fillInfoCollection.push_back(FillInfo(6998, false, 320500, 320500, "fill 6998"));
	fillInfoCollection.push_back(FillInfo(7003, false, 320569, 320571, "fill 7003"));
	fillInfoCollection.push_back(FillInfo(7005, false, 320673, 320674, "fill 7005"));
	fillInfoCollection.push_back(FillInfo(7006, false, 320688, 320688, "fill 7006"));
	fillInfoCollection.push_back(FillInfo(7008, false, 320712, 320712, "fill 7008"));
	fillInfoCollection.push_back(FillInfo(7013, false, 320757, 320757, "fill 7013"));
	fillInfoCollection.push_back(FillInfo(7017, false, 320804, 320809, "fill 7017"));
	fillInfoCollection.push_back(FillInfo(7018, false, 320821, 320824, "fill 7018"));
	fillInfoCollection.push_back(FillInfo(7020, false, 320838, 320841, "fill 7020"));
	fillInfoCollection.push_back(FillInfo(7024, false, 320853, 320859, "fill 7024"));
	fillInfoCollection.push_back(FillInfo(7026, false, 320887, 320888, "fill 7026"));
	fillInfoCollection.push_back(FillInfo(7031, false, 320916, 320920, "fill 7031"));
	fillInfoCollection.push_back(FillInfo(7033, false, 320933, 320941, "fill 7033"));
	fillInfoCollection.push_back(FillInfo(7035, false, 320980, 320980, "fill 7035"));
	fillInfoCollection.push_back(FillInfo(7036, false, 320995, 320996, "fill 7036"));
	fillInfoCollection.push_back(FillInfo(7037, false, 321004, 321012, "fill 7037"));
	fillInfoCollection.push_back(FillInfo(7039, false, 321051, 321055, "fill 7039"));
	fillInfoCollection.push_back(FillInfo(7040, false, 321067, 321069, "fill 7040"));
	fillInfoCollection.push_back(FillInfo(7042, false, 321119, 321126, "fill 7042"));
	fillInfoCollection.push_back(FillInfo(7043, false, 321134, 321140, "fill 7043"));
	fillInfoCollection.push_back(FillInfo(7045, false, 321149, 321149, "fill 7045"));
	fillInfoCollection.push_back(FillInfo(7047, false, 321162, 321167, "fill 7047"));
	fillInfoCollection.push_back(FillInfo(7048, false, 321177, 321178, "fill 7048"));
	fillInfoCollection.push_back(FillInfo(7052, false, 321218, 321221, "fill 7052"));
	fillInfoCollection.push_back(FillInfo(7053, false, 321230, 321233, "fill 7053"));
	fillInfoCollection.push_back(FillInfo(7054, false, 321261, 321262, "fill 7054"));
	fillInfoCollection.push_back(FillInfo(7055, false, 321283, 321296, "fill 7055"));
	fillInfoCollection.push_back(FillInfo(7056, false, 321305, 321313, "fill 7056"));
	fillInfoCollection.push_back(FillInfo(7058, false, 321393, 321397, "fill 7058"));
	fillInfoCollection.push_back(FillInfo(7061, false, 321414, 321415, "fill 7061"));
	fillInfoCollection.push_back(FillInfo(7063, false, 321431, 321436, "fill 7063"));
	fillInfoCollection.push_back(FillInfo(7065, false, 321457, 321461, "fill 7065"));
	fillInfoCollection.push_back(FillInfo(7069, false, 321475, 321475, "fill 7069"));
	fillInfoCollection.push_back(FillInfo(7078, false, 321709, 321712, "fill 7078"));
	fillInfoCollection.push_back(FillInfo(7080, false, 321730, 321735, "fill 7080"));
	fillInfoCollection.push_back(FillInfo(7083, false, 321755, 321760, "fill 7083"));
	fillInfoCollection.push_back(FillInfo(7087, false, 321773, 321781, "fill 7087"));
	fillInfoCollection.push_back(FillInfo(7088, false, 321794, 321796, "fill 7088"));
	fillInfoCollection.push_back(FillInfo(7090, false, 321813, 321820, "fill 7090"));
	fillInfoCollection.push_back(FillInfo(7091, false, 321831, 321834, "fill 7091"));
	fillInfoCollection.push_back(FillInfo(7092, false, 321879, 321880, "fill 7092"));
	fillInfoCollection.push_back(FillInfo(7095, false, 321887, 321887, "fill 7095"));
	fillInfoCollection.push_back(FillInfo(7097, false, 321908, 321909, "fill 7097"));
	fillInfoCollection.push_back(FillInfo(7098, false, 321917, 321919, "fill 7098"));
	fillInfoCollection.push_back(FillInfo(7099, false, 321933, 321933, "fill 7099"));
	fillInfoCollection.push_back(FillInfo(7101, false, 321960, 321961, "fill 7101"));
	fillInfoCollection.push_back(FillInfo(7105, false, 321973, 321975, "fill 7105"));
	fillInfoCollection.push_back(FillInfo(7108, false, 321988, 321990, "fill 7108"));
	fillInfoCollection.push_back(FillInfo(7109, false, 322013, 322014, "fill 7109"));
	fillInfoCollection.push_back(FillInfo(7110, false, 322022, 322022, "fill 7110"));
	fillInfoCollection.push_back(FillInfo(7112, false, 322040, 322040, "fill 7112"));
	fillInfoCollection.push_back(FillInfo(7114, false, 322057, 322057, "fill 7114"));
	fillInfoCollection.push_back(FillInfo(7117, false, 322068, 322068, "fill 7117"));
	fillInfoCollection.push_back(FillInfo(7118, false, 322079, 322088, "fill 7118"));
	fillInfoCollection.push_back(FillInfo(7120, false, 322106, 322106, "fill 7120"));
	fillInfoCollection.push_back(FillInfo(7122, false, 322113, 322118, "fill 7122"));
	fillInfoCollection.push_back(FillInfo(7123, false, 322179, 322179, "fill 7123"));
	fillInfoCollection.push_back(FillInfo(7124, false, 322201, 322222, "fill 7124"));
	fillInfoCollection.push_back(FillInfo(7125, false, 322252, 322252, "fill 7125"));
	fillInfoCollection.push_back(FillInfo(7127, false, 322317, 322324, "fill 7127"));
	fillInfoCollection.push_back(FillInfo(7128, false, 322332, 322332, "fill 7128"));
	fillInfoCollection.push_back(FillInfo(7131, false, 322348, 322348, "fill 7131"));
	fillInfoCollection.push_back(FillInfo(7132, false, 322355, 322356, "fill 7132"));
	fillInfoCollection.push_back(FillInfo(7133, false, 322381, 322381, "fill 7133"));
	fillInfoCollection.push_back(FillInfo(7135, false, 322407, 322407, "fill 7135"));
	fillInfoCollection.push_back(FillInfo(7137, false, 322430, 322431, "fill 7137"));
	fillInfoCollection.push_back(FillInfo(7139, false, 322480, 322492, "fill 7139"));
	fillInfoCollection.push_back(FillInfo(7142, false, 322510, 322510, "fill 7142"));
	fillInfoCollection.push_back(FillInfo(7144, false, 322599, 322617, "fill 7144"));
	fillInfoCollection.push_back(FillInfo(7145, false, 322625, 322633, "fill 7145"));

	fillInfoCollection.push_back(FillInfo(7211, false, 323363, 323379, "fill 7211"));
	fillInfoCollection.push_back(FillInfo(7212, false, 323388, 323399, "fill 7212"));
	fillInfoCollection.push_back(FillInfo(7213, false, 323413, 323423, "fill 7213"));
	fillInfoCollection.push_back(FillInfo(7217, false, 323470, 323475, "fill 7217"));
	fillInfoCollection.push_back(FillInfo(7218, false, 323487, 323495, "fill 7218"));
	fillInfoCollection.push_back(FillInfo(7220, false, 323513, 323513, "fill 7220"));
	fillInfoCollection.push_back(FillInfo(7221, false, 323523, 323526, "fill 7221"));
	fillInfoCollection.push_back(FillInfo(7234, false, 323693, 323702, "fill 7234"));
	fillInfoCollection.push_back(FillInfo(7236, false, 323725, 323727, "fill 7236"));
	fillInfoCollection.push_back(FillInfo(7239, false, 323755, 323755, "fill 7239"));
	fillInfoCollection.push_back(FillInfo(7240, false, 323775, 323778, "fill 7240"));
	fillInfoCollection.push_back(FillInfo(7242, false, 323790, 323794, "fill 7242"));
	fillInfoCollection.push_back(FillInfo(7245, false, 323841, 323857, "fill 7245"));
	fillInfoCollection.push_back(FillInfo(7252, false, 323940, 323954, "fill 7252"));
	fillInfoCollection.push_back(FillInfo(7253, false, 323976, 323997, "fill 7253"));
	fillInfoCollection.push_back(FillInfo(7256, false, 324021, 324022, "fill 7256"));
	fillInfoCollection.push_back(FillInfo(7259, false, 324077, 324078, "fill 7259"));
	fillInfoCollection.push_back(FillInfo(7264, false, 324201, 324209, "fill 7264"));
	fillInfoCollection.push_back(FillInfo(7265, false, 324237, 324237, "fill 7265"));
	fillInfoCollection.push_back(FillInfo(7266, false, 324245, 324245, "fill 7266"));
	fillInfoCollection.push_back(FillInfo(7270, false, 324293, 324293, "fill 7270"));
	fillInfoCollection.push_back(FillInfo(7271, false, 324313, 324318, "fill 7271"));
	fillInfoCollection.push_back(FillInfo(7274, false, 324418, 324420, "fill 7274"));
	fillInfoCollection.push_back(FillInfo(7299, false, 324564, 324564, "fill 7299"));
	fillInfoCollection.push_back(FillInfo(7300, false, 324571, 324571, "fill 7300"));
	fillInfoCollection.push_back(FillInfo(7304, false, 324612, 324612, "fill 7304"));
	fillInfoCollection.push_back(FillInfo(7308, false, 324725, 324729, "fill 7308"));
	fillInfoCollection.push_back(FillInfo(7309, false, 324747, 324772, "fill 7309"));
	fillInfoCollection.push_back(FillInfo(7310, false, 324785, 324791, "fill 7310"));
	fillInfoCollection.push_back(FillInfo(7314, false, 324835, 324846, "fill 7314"));
	fillInfoCollection.push_back(FillInfo(7315, false, 324878, 324878, "fill 7315"));
	fillInfoCollection.push_back(FillInfo(7317, false, 324897, 324897, "fill 7317"));
	fillInfoCollection.push_back(FillInfo(7320, false, 324968, 324970, "fill 7320"));
	fillInfoCollection.push_back(FillInfo(7321, false, 324980, 324980, "fill 7321"));
	fillInfoCollection.push_back(FillInfo(7324, false, 324997, 325001, "fill 7324"));
	fillInfoCollection.push_back(FillInfo(7328, false, 325022, 325022, "fill 7328"));
	fillInfoCollection.push_back(FillInfo(7331, false, 325057, 325057, "fill 7331"));
	fillInfoCollection.push_back(FillInfo(7333, false, 325097, 325117, "fill 7333"));
	fillInfoCollection.push_back(FillInfo(7334, false, 325159, 325175, "fill 7334"));
}

void InitFillInfoCollection()
{
	InitFillInfoCollection2016();
	InitFillInfoCollection2017();
	InitFillInfoCollection2018();
}

#endif
