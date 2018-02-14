#include "stdafx.h"
#include "DESedeEncryptManager.h"


Encryption::DESedeEncryptManager::DESedeEncryptManager(char const* key_data, unsigned char const* salt, const uint16_t nrounds)
{
	if (strlen(key_data) < 24)
		throw new std::length_error("Your key should be at least 24 characters long");

	
	DES_cblock cKey1 = { key_data[0], key_data[3], key_data[6], key_data[9], key_data[12], key_data[15], key_data[18], key_data[21] };
	DES_cblock cKey2 = { key_data[1], key_data[4], key_data[7], key_data[10], key_data[13], key_data[16], key_data[19], key_data[22] };
	DES_cblock cKey3 = { key_data[2], key_data[5], key_data[8], key_data[11], key_data[14], key_data[17], key_data[20], key_data[23] };
	if ((DES_set_key_checked(&cKey1, this->SchKey1) || DES_set_key_checked(&cKey2, this->SchKey2) || DES_set_key_checked(&cKey3, this->SchKey3)) == -2)
	{
		throw new std::bad_exception("");
	}
		
}


Encryption::DESedeEncryptManager::~DESedeEncryptManager(){}

std::string Encryption::DESedeEncryptManager::encrypt(const char *)
{
	std::random_device rand;
	std::mt19937_64(rand());

	std::uniform_int_distribution<int> dist(1, 256);

	DES_cblock iv = (DES_cblock)malloc(8);
	for (uint16_t i = 0; i < 8; ++i)
	{

	}

	return std::string();
}

std::string Encryption::DESedeEncryptManager::decrypt(const char *)
{
	return std::string();
}
