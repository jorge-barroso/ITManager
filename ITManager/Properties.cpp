#include "stdafx.h"
#include "Properties.h"
#include <sstream>
#include <iterator>
#include <vector>

Properties::Properties(){}


Properties::~Properties(){}

void Properties::load(Files::FileReader &reader)
{
	std::string line;
	size_t pos;
	while (reader.readLine(line))
	{
		pos = line.find('=', 1);
		this->setProperty(line.substr(0, pos), line.substr(pos));
	}
}

void Properties::save()
{
	Files::FileWriter writer(this->propertiesFile);
	this->save(writer);
}

void Properties::save(Files::FileWriter &fileWriter)
{
	for (const auto& entry : this->properties)
	{
		fileWriter.writeLine(entry.first + '=' + entry.second);
	}
}

std::string Properties::getProperty(std::string const& key, std::string const& defaultValue)
{
	std::unordered_map<std::string, std::string>::iterator&& it = this->properties.find(key);

	return (it == this->properties.end()) ? defaultValue : it->second;
}

void Properties::setProperty(std::string const& key, std::string const& value)
{
	this->properties.insert({ key, value });
}

std::unordered_map<std::string, std::string> Properties::getPropertyMap()
{
	return this->properties;
}
