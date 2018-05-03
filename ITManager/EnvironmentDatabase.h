#pragma db object
#include "Environment.h"
#include "Database.h"

#include "odb\core.hxx"

#include<memory>

namespace Models
{
	class EnvironmentDatabase
	{
	public:
		EnvironmentDatabase(const Models::Environment &environment, const Models::Database &db);
		~EnvironmentDatabase();
	private:
		friend class odb::access;
		EnvironmentDatabase() {}

		#pragma id
		std::shared_ptr<Models::Environment> environment;
		#pragma id		
		std::shared_ptr<Models::Database> db;
	};
}
