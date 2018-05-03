#pragma db object
#include <cstdlib>
#include "odb\core.hxx"
#include "ServerProviders.h"
namespace Models
{
	class Instance
	{
	public:
		~Instance();
		uint16_t getId();

		std::string getName();
		Models::Instance setName(std::string const& name);

		std::string getInstanceId();
		Models::Instance setInstanceId(const std::string &instanceId);

		ServerProviders::ServerProvider getServerProvider();
		Models::Instance setServerProvider(ServerProviders::ServerProvider provider);
	private:
		friend class odb::access;
		Instance() {}

		#pragma db id
		uint16_t id;

		std::string name;

		std::string instanceId;

		ServerProviders::ServerProvider provider;
	};
}
