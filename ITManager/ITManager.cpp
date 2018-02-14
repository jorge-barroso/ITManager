// ITManager.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "FileReader.h"
#include "FileWriter.h"

#include "Properties.h"

#include "AESEncryptManager.h"
#include "DESedeEncryptManager.h"
#include "BcryptHashManager.h"
#include "EncryptManager.h"
#include "EncAlgorithm.h"
#include <array>
#include <experimental/filesystem>

#include <iostream>

const uint16_t ARRAY_SIZE = 9;
std::array<std::string, ARRAY_SIZE> OPT_ARRAY{ "Encrypt a string", "Decrypt a string", "Hash a string", "Cleanup a database", "Run a deployment", "Configure", "Add environment", "Edit Environment", "Exit" };

const std::string MAIN_TITLE = "Hi this is to the Self Service Portal assistant, choose an action to perform:";
const std::string ENCRYPT_MENU = "Encrypt main menu.txt";
const std::string DECRYPT_MENU = "Decrypt main menu.txt";
const std::string CLEANUP_MENU = "What's environment do you want to clean up?";
const std::string DEPLOY_MENU = "What's environment do you want to deploy to?";

const std::string OPTS[] = { "1", "2", "3", "4", "5", "6", "7","8", "9" };

const char NEW_LINE = '\n';

std::string menu = "";

void getMenu(std::string const&, std::array<std::string, ARRAY_SIZE> const& = OPT_ARRAY);
uint16_t getOption(const uint16_t = 1, const uint16_t = ARRAY_SIZE);
void createConfig(Properties properties, std::string const& configFile);
std::experimental::filesystem::path getConfigFile(std::string const&, const bool = true);
Properties getProperties(const std::experimental::filesystem::path);

int main()
{
	const std::experimental::filesystem::path &&configFile = getConfigFile("pfmanager.properties");
	Properties&& properties = getProperties(configFile);

	Encryption::EncryptManager *em;

	getMenu(MAIN_TITLE);

	do {
		switch (getOption())
		{
			//Encrypt
		case 1:
		{
			OPT_ARRAY = { "AES", "DESede", "RSA" };
			getMenu(ENCRYPT_MENU, OPT_ARRAY);
			switch (Encryption::EncAlgorithm(getOption(1, 3)))
			{
			case Encryption::EncAlgorithm::AES:
			{
				std::cout << "Type here what you want to encrypt: ";
				char *input = (char *)malloc(100);
				std::fgets(input, INT_MAX, stdin);
				em = &Encryption::AESEncryptManager((char *)"key_data", (unsigned char *)"salt", (uint16_t)24);
				break;
			}
			case Encryption::EncAlgorithm::DESede:
			{
				em = &Encryption::DESedeEncryptManager((char *)"key_data", (unsigned char *)"salt", (uint16_t)24);
				break;
			}
			}
			break;
		}
		//Decrypt
		case 2:
			/*OPT_ARRAY = { "AES", "DESede" };
			getMenu(DECRYPT_MENU, OPT_ARRAY);
			switch (DecAlgorithm(getOption(1, 2)))
			{
			case DecAlgorithm::AES:
			break;
			case DecAlgorithm::DESede:
			break;
			}*/
			break;
		//Hash String
		case 3:
			//TODO BCrypt and Co.
			break;
		//Cleanup DB
		case 4:
			//TODO get list of environments with databases listed
			break;
		//Deploy
		case 5:
			//TODO get list of environments with servers where we can deploy
			break;
		//Reset config
		case 6:
			std::experimental::filesystem::remove(configFile);
			createConfig(properties, configFile.string());
			break;
		//TODO add new environment
		case 7:
			break;
		//Edit environment
		case 8:
			break;
		default:
			return 0;
		}
	} while (true);

	system("pause");
	return 0;
}

void getMenu(std::string const& menuTitle, std::array<std::string, ARRAY_SIZE> const& options)
{
	menu = menuTitle + NEW_LINE + NEW_LINE;
	for (uint16_t i = 0; (i<options.size() && !options.at(i).empty()); ++i)
	{
		menu += OPTS[i] + ". " + options.at(i) + NEW_LINE + NEW_LINE;
	}
	menu += NEW_LINE;
}

uint16_t getOption(const uint16_t min, const uint16_t max)
{
	std::cin.clear();
	char optChar;
	uint16_t finalOpt;

	do {
		std::cout << menu << std::endl;

		std::cin.get(optChar);

		std::cout << std::endl << std::endl;
	} while (!isdigit(optChar) && ((finalOpt = atoi(&optChar)) - min <= max - min));
	return finalOpt;
}

void createConfig(Properties properties, std::string const& configFile)
{

	const std::unordered_map<std::string, std::string> CONFIG_OPTIONS{ { "github.username", "GitHub Username" },
																	   { "github.password", "GitHub Password" },
																	   { "encrypt.key", "Secret key of 32 characters for encryption/decryption"},
																	   { "encrypt.salt", "Salt key of 32 characters for encryption/decryption" },
																	   { "ssh.key_file.public", "Path to your public ssh key" },
																	   { "ssh.key_file.private", "Path to your private ssh key" } };

	std::string optionValue;
	for (const auto& configOption : CONFIG_OPTIONS)
	{
		std::string const&& currentValue = properties.getProperty(configOption.first, "No current value");
		std::cout << configOption.second << " (" + currentValue + ")" << ": ";
		std::getline(std::cin, optionValue);
		properties.setProperty(configOption.first, optionValue);
	}

	Files::FileWriter writer(configFile);
	properties.save(writer);
}

std::experimental::filesystem::path getConfigFile(std::string const& filename, const bool useLocalPath)
{
	const std::experimental::filesystem::path path(filename);

	if (!useLocalPath)
		return path;

	char* location;
	size_t len;
	_dupenv_s(&location, &len, "APPDATA");

	std::string loc = location;
	loc += "\\ITManager";

	return std::experimental::filesystem::path(loc + filename);
}

Properties getProperties(const std::experimental::filesystem::path configFile)
{

	Properties properties;
	if (std::experimental::filesystem::exists(configFile))
	{
		Files::FileReader reader(configFile.string());
		properties.load(reader);
	}
	else
	{
		std::experimental::filesystem::create_directories(configFile.parent_path());
		std::cout << "It looks like it's the first time you run this application, please answer the following questions to configure your environment:" << std::endl << std::endl;
		createConfig(properties, configFile.string());
		Files::FileWriter writer(configFile);
		properties.save(writer);
	}

	return properties;
}
