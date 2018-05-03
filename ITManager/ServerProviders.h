#pragma db object
#include <unordered_map>
#include <array>

class ServerProviders
{
public:
	enum ServerProvider
	{
		AWS,
		DIGITAL_OCEAN,
		UNSUPPORTED_PROVIDER
	};

	static std::string toString(const ServerProviders::ServerProvider provider);
	static ServerProviders::ServerProvider byName(const std::string &providerName);

private:
	const static std::array<std::string, 3> providerNames;

	const static std::unordered_map<std::string, ServerProviders::ServerProvider> providersByName;
};
