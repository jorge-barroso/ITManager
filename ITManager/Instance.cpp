#include "stdafx.h"
#include "Instance.h"


Models::Instance::Instance()
{
}


Models::Instance::~Instance()
{
}

uint16_t Models::Instance::getId()
{
	return this->id;
}

std::string Models::Instance::getAlias()
{
	return this->alias;
}

Models::Instance Models::Instance::setAlias(std::string const & alias)
{
	this->alias = alias;
	return *this;
}

ServerProvider Models::Instance::getServerProvider()
{
	return this->provider;
}

Models::Instance Models::Instance::setServerProvider(ServerProvider provider)
{
	this->provider = provider;
	return *this;
}
