#include "stdafx.h"
#include "EnvironmentInstance.h"


Models::EnvironmentInstance::EnvironmentInstance(const Models::Environment &environment, const Models::Instance &instance)
	:
	environment(std::make_shared<Models::Environment>(environment)),
	instance(std::make_shared<Models::Instance>(instance))
{}

Models::EnvironmentInstance::~EnvironmentInstance()
{
}
