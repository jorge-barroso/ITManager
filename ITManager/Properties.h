#pragma once
#include "FileReader.h"
#include "FileWriter.h"
#include <unordered_map>
#include <map>
class Properties
{
public:
	explicit Properties();
	~Properties();
	void load(Files::FileReader &reader);
	void save();
	void save(Files::FileWriter &fileWriter);
	std::string getProperty(std::string const& key, std::string const& defaultValue = NULL);
	void setProperty(std::string const& key, std::string const& value);
	std::unordered_map<std::string, std::string> getPropertyMap();
private:
	std::unordered_map<std::string, std::string> properties;
	std::string propertiesFile;
};

