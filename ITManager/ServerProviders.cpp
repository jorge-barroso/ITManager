#include "stdafx.h"
#include "ServerProviders.h"

const std::array<std::string, 3> ServerProviders::providerNames = { "AWS", "DIGITAL_OCEAN", "UNSUPPORTED_PROVIDER" };

const std::unordered_map<std::string, ServerProviders::ServerProvider> ServerProviders::providersByName = { { "AWS",					 ServerProviders::ServerProvider::AWS },
																											{ "DIGITAL_OCEAN",		 ServerProviders::ServerProvider::DIGITAL_OCEAN },
																											{ "UNSUPPORTED_PROVIDER", ServerProviders::ServerProvider::UNSUPPORTED_PROVIDER} };

std::string ServerProviders::toString(const ServerProviders::ServerProvider provider)
{
	return provider >= providerNames.size() ? providerNames[ServerProviders::ServerProvider::UNSUPPORTED_PROVIDER] : providerNames[provider];
}

ServerProviders::ServerProvider ServerProviders::byName(const std::string & providerName)
{
	const std::unordered_map<std::string, ServerProviders::ServerProvider>::const_iterator it = providersByName.find(providerName);
	if (it == providersByName.end())
		return ServerProviders::ServerProvider::UNSUPPORTED_PROVIDER;
	else
		return it->second;
}

