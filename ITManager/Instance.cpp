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

std::string Models::Instance::getName()
{
	return this->name;
}

Models::Instance Models::Instance::setName(std::string const & name)
{
	this->name = name;
	return *this;
}

std::string Models::Instance::getInstanceId()
{
	return this->instanceId;
}

Models::Instance Models::Instance::setInstanceId(const std::string & instanceId)
{
	this->instanceId = instanceId;
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
