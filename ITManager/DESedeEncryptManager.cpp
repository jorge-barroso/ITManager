#include "stdafx.h"
#include "DESedeEncryptManager.h"

const std::string Encryption::DESedeEncryptManager::encrypt(const unsigned char * salt, const uint16_t nrounds, const unsigned char * key, size_t key_size)
{
	return Encryption::EncryptManager::encrypt(EVP_des_ede3_cbc(), salt, nrounds, key, key_size);
}

const std::string Encryption::DESedeEncryptManager::decrypt(const unsigned char * salt, const uint16_t nrounds, char * ciphertext)
{
	return Encryption::EncryptManager::decrypt(EVP_des_ede3_cbc(), salt, nrounds, ciphertext);
}
