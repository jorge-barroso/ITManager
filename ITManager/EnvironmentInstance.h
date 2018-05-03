#pragma db object
#include "Environment.h"
#include "Instance.h"

#include <memory>

namespace Models
{
	class EnvironmentInstance
	{
	public:
		EnvironmentInstance(const Models::Environment &environment, const Models::Instance &instance);
		~EnvironmentInstance();
	private:
		friend class odb::access;
		EnvironmentInstance() {}

		std::shared_ptr<Models::Environment> environment;
		std::shared_ptr<Models::Instance> instance;
	};
}
