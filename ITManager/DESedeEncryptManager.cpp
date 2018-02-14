#include "stdafx.h"
#include "DESedeEncryptManager.h"


Encryption::DESedeEncryptManager::DESedeEncryptManager(const char key_data[24], unsigned char const* salt, const uint16_t nrounds)
{
	if (strlen(key_data) < 24)
		throw new std::length_error("Your key should be at least 24 characters long");

	
	DES_cblock cKey1 = { key_data[0], key_data[3], key_data[6], key_data[9], key_data[12], key_data[15], key_data[18], key_data[21] };
	DES_cblock cKey2 = { key_data[1], key_data[4], key_data[7], key_data[10], key_data[13], key_data[16], key_data[19], key_data[22] };
	DES_cblock cKey3 = { key_data[2], key_data[5], key_data[8], key_data[11], key_data[14], key_data[17], key_data[20], key_data[23] };
	if ((DES_set_key_checked(&cKey1, this->SchKey1) || DES_set_key_checked(&cKey2, this->SchKey2) || DES_set_key_checked(&cKey3, this->SchKey3)) == -2)
	{
		throw new DesWeakKeyException("");
	}
		
}


Encryption::DESedeEncryptManager::~DESedeEncryptManager(){}

std::string Encryption::DESedeEncryptManager::encrypt(const char * key)
{
	std::random_device rand;
	std::mt19937_64 mt(rand());

	std::uniform_int_distribution<int> dist(1, 256);

	char cIv[8];
	for (uint16_t i = 0; i < 8; ++i)
	{
		cIv[i] = dist(mt);
	}

	DES_cblock iv = { cIv[0], cIv[1], cIv[2], cIv[3], cIv[4], cIv[5], cIv[6], cIv[7] };

	DES_set_odd_parity(&iv);

	const uint16_t length = sizeof(&key);
	unsigned char ciphertext[length];

	DES_ede3_cbc_encrypt((unsigned char*)key, ciphertext, length, this->SchKey1, this->SchKey2, this->SchKey3, &iv, DES_ENCRYPT);

	return Base64::encode(ciphertext, length);
}

std::string Encryption::DESedeEncryptManager::decrypt(const char *)
{

	return std::string();
}
