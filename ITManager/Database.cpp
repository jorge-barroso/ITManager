#include "stdafx.h"
#include "Database.h"



Database::Database(uint16_t const id, std::string const& url, uint16_t const port, std::string const& user, std::string const& password, std::string const& schema)
{

}

Database::~Database()
{
	
}

Database Database::setId(uint16_t id)
{
	this->id = id;
	return *this;
}

uint16_t Database::getId()
{
	return this->id;
}

Database Database::setUrl(std::string url)
{
	this->url = url;
	return *this;
}

std::string Database::getUrl()
{
	return this->url;
}

Database Database::setPort(uint16_t port)
{
	return *this;
}

uint16_t Database::getPort()
{
	return this->port;
}

Database Database::setUser(std::string user)
{
	return *this;
}

std::string Database::getUser()
{
	return std::string();
}

Database Database::setPassword(std::string password)
{
	return *this;
}

std::string Database::getPassword()
{
	return this->password;
}

Database Database::setSchema(std::string schema)
{
	return *this;
}

std::string Database::getSchema()
{
	return this->schema;
}
