#pragma db object
#include <unordered_map>
enum class ServerProvider
{
	AWS,
	DIGITAL_OCEAN
};

const std::string providerNames[2] = { "AWS", "DIGITAL_OCEAN" };

const std::unordered_map<std::string, ServerProvider> providersByName = { {"AWS", ServerProvider::AWS },
																		  { "DIGITAL_OCEAN", ServerProvider::DIGITAL_OCEAN } };