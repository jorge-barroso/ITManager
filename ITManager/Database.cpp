#include "stdafx.h"
#include "Database.h"



Models::Database::Database(std::string const& url, uint16_t const port, std::string const& user, std::string const& password, std::string const& schema)
	:
	url(url),
	port(port),
	user(user),
	password(password),
	schema(schema){}

Models::Database::~Database(){}

Models::Database Models::Database::setId(uint16_t id)
{
	this->id = id;
	return *this;
}

uint16_t Models::Database::getId()
{
	return this->id;
}

Models::Database Models::Database::setUrl(std::string const& url)
{
	this->url = url;
	return *this;
}

std::string Models::Database::getUrl()
{
	return this->url;
}

Models::Database Models::Database::setPort(uint16_t port)
{
	this->port = port;
	return *this;
}

uint16_t Models::Database::getPort()
{
	return this->port;
}

Models::Database Models::Database::setUser(std::string const& user)
{
	this->user = user;
	return *this;
}

std::string Models::Database::getUser()
{
	return this->user;
}

Models::Database Models::Database::setPassword(std::string const& password)
{
	this->password = password;
	return *this;
}

std::string Models::Database::getPassword()
{
	return this->password;
}

Models::Database Models::Database::setSchema(std::string const& schema)
{
	this->schema = schema;
	return *this;
}

std::string Models::Database::getSchema()
{
	return this->schema;
}
