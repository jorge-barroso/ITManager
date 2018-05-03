#include "stdafx.h"
#include "EnvironmentDatabase.h"

Models::EnvironmentDatabase::EnvironmentDatabase(const Models::Environment &environment, const Models::Database &db)
	:
	environment(std::make_shared<Models::Environment>(environment)),
	db(std::make_shared<Models::Database>(db))
{}

Models::EnvironmentDatabase::~EnvironmentDatabase()
{
}
