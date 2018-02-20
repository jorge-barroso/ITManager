#pragma db object
#include <cstdlib>
#include "odb\core.hxx"
#include "ServerProvider.h"
namespace Models
{
	class Instance
	{
	public:
		~Instance();
		uint16_t getId();

		std::string getAlias();
		Models::Instance setAlias(std::string const& alias);

		ServerProvider getServerProvider();
		Models::Instance setServerProvider(ServerProvider provider);
	private:
		friend class odb::access;
		Instance() {}

		#pragma db id
		uint16_t id;

		std::string alias;

		ServerProvider provider;
	};
}
