#include <unordered_map>
const enum class Region
{
	CA_CENTRAL_1,

	US_EAST_1,
	US_EAST_2,
	US_WEST_1,
	US_WEST_2,

	EU_CENTRAL_1,
	EU_WEST_1,
	EU_WEST_2,
	EU_WEST_3,

	AP_SOUTH_1,
	AP_NORTHEAST_1,
	AP_NORTHEAST_2,
	AP_SOUTHEAST_1,
	AP_SOUTHEAST_2,

	CN_NORTH_1,

	SA_EAST_1
};

const std::string regionsNames[16] {"CA_CENTRAL_1",
						 "US_EAST_1",
						 "US_EAST_2",
						 "US_WEST_1",
						 "US_WEST_2",
						 "EU_CENTRAL_1",
						 "EU_WEST_1",
						 "EU_WEST_2",
						 "EU_WEST_3",
						 "AP_SOUTH_1",
						 "AP_NORTHEAST_1",
						 "AP_NORTHEAST_2",
						 "AP_SOUTHEAST_1",
						 "AP_SOUTHEAST_2",
						 "CN_NORTH_1",
						 "SA_EAST_1", };

const std::unordered_map<std::string, Region> regionsByName = { { "CA_CENTRAL_1", Region::CA_CENTRAL_1 },
																 { "US_EAST_1", Region::US_EAST_1 },
																 { "US_EAST_2", Region::US_EAST_2 },
																 { "US_WEST_1", Region::US_WEST_1 },
																 { "US_WEST_2", Region::US_WEST_2 },
																 { "EU_CENTRAL_1", Region::EU_CENTRAL_1 },
																 { "EU_WEST_1", Region::EU_WEST_1 },
																 { "EU_WEST_2", Region::EU_WEST_2 },
																 { "EU_WEST_3", Region::EU_WEST_3 },
																 { "AP_SOUTH_1", Region::AP_SOUTH_1 },
																 { "AP_NORTHEAST_1", Region::AP_NORTHEAST_1 },
																 { "AP_NORTHEAST_2", Region::AP_NORTHEAST_2 },
																 { "AP_SOUTHEAST_1", Region::AP_SOUTHEAST_1 },
																 { "AP_SOUTHEAST_2", Region::AP_SOUTHEAST_2 },
																 { "CN_NORTH_1", Region::CN_NORTH_1 },
																 { "SA_EAST_1", Region::SA_EAST_1 } };
