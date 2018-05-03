#pragma db object
#include <string>
#include "odb\core.hxx"

namespace Models
{
	class Environment
	{
		public:
			Environment(const std::string &alias);
			~Environment();
		private:
			friend class odb::access;
			Environment() {}

			#pragma db id
			uint16_t id;

			std::string alias;
	};
}
