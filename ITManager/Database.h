#pragma db object
#include <cstdlib>
#include "AESEncryptManager.h"
#include "odb\core.hxx"

namespace Models
{
	class Database
	{
	public:
		Database(std::string const& url, uint16_t const port, std::string const& user, std::string const& password, std::string const& schema);

		Database setId(uint16_t id);
		uint16_t getId();

		Database setAlias(std::string const& alias);
		std::string getAlias();

		Database setUrl(std::string const& url);
		std::string getUrl();

		Database setPort(uint16_t port);
		uint16_t getPort();

		Database setUser(std::string const& user);
		std::string getUser();

		Database setPassword(std::string const& password);
		std::string getPassword();

		Database setSchema(std::string const& schema);
		std::string getSchema();

		~Database();
	private:
		friend class odb::access;
		Database() {}

		#pragma db id
		uint16_t id;

		std::string alias;
		std::string url;
		uint16_t port;
		std::string user;
		std::string password;
		std::string schema;
	};
}
