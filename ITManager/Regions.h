#pragma once
#include <unordered_map>
#include <array>

class Regions
{
public:
	enum Region {
		CA_CENTRAL_1 = 0,

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

		SA_EAST_1,

		NO_REGION
	};

	static std::string getRegionName(const Regions::Region region);
	static Regions::Region getRegionByName(const std::string &name);

private:
	const static std::array<std::string, 17> RegionsNames;
	const static  std::unordered_map<std::string, Region> RegionsByName;
};