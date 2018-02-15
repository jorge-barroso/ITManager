#pragma db object
#include <string>
#include <cstdlib>
#include "odb\core.hxx"
class Database
{
public:
	Database(uint16_t const, std::string const&, uint16_t const, std::string const&, std::string const&, std::string const&);
	
	Database setId(uint16_t id);
	uint16_t getId();
	
	Database setUrl(std::string url);
	std::string getUrl();
	
	Database setPort(uint16_t port);
	uint16_t getPort();
	
	Database setUser(std::string user);
	std::string getUser();
	
	Database setPassword(std::string password);
	std::string getPassword();
	
	Database setSchema(std::string schema);
	std::string getSchema();
	
	~Database();
private:
	friend class odb::access;
	Database() {}

	#pragma db id
	uint16_t id;
	
	std::string url;
	uint16_t port;
	std::string user;
	std::string password;
	std::string schema;
};

