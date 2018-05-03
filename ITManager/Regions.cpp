#include "stdafx.h"
#include "Regions.h"

const std::array<std::string, 17> Regions::RegionsNames = { "CA_CENTRAL_1",
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
															"SA_EAST_1",
															"NO_REGION" };

const std::unordered_map<std::string, Regions::Region> Regions::RegionsByName = { { "CA_CENTRAL_1", Regions::Region::CA_CENTRAL_1 },
																				  { "US_EAST_1", Regions::Region::US_EAST_1 },
																				  { "US_EAST_2", Regions::Region::US_EAST_2 },
																				  { "US_WEST_1", Regions::Region::US_WEST_1 },
																				  { "US_WEST_2", Regions::Region::US_WEST_2 },
																				  { "EU_CENTRAL_1", Regions::Region::EU_CENTRAL_1 },
																				  { "EU_WEST_1", Regions::Region::EU_WEST_1 },
																				  { "EU_WEST_2", Regions::Region::EU_WEST_2 },
																				  { "EU_WEST_3", Regions::Region::EU_WEST_3 },
																				  { "AP_SOUTH_1", Regions::Region::AP_SOUTH_1 },
																				  { "AP_NORTHEAST_1", Regions::Region::AP_NORTHEAST_1 },
																				  { "AP_NORTHEAST_2", Regions::Region::AP_NORTHEAST_2 },
																				  { "AP_SOUTHEAST_1", Regions::Region::AP_SOUTHEAST_1 },
																				  { "AP_SOUTHEAST_2", Regions::Region::AP_SOUTHEAST_2 },
																				  { "CN_NORTH_1", Regions::Region::CN_NORTH_1 },
																				  { "SA_EAST_1", Regions::Region::SA_EAST_1 },
																				  { "NO_REGION", Regions::Region::NO_REGION } };

std::string Regions::toString(const Regions::Region region)
{
	return region>=RegionsNames.size() ? Regions::RegionsNames[Regions::Region::NO_REGION] : RegionsNames[region];
}

Regions::Region Regions::byName(const std::string & name)
{
	std::unordered_map<std::string, Regions::Region>::const_iterator it = Regions::RegionsByName.find(name);
	if (it == RegionsByName.end())
		return Regions::Region::NO_REGION;
	else
		return it->second;
}
