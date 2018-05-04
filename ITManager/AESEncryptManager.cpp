#include "stdafx.h"
#include "AESEncryptManager.h"

const std::string Encryption::AESEncryptManager::encrypt(const unsigned char * salt, const uint16_t nrounds, const unsigned char * key, size_t key_size)
{
	return Encryption::EncryptManager::encrypt(EVP_aes_256_cbc(), salt, nrounds, key, key_size);
}

const std::string Encryption::AESEncryptManager::decrypt(const unsigned char * salt, const uint16_t nrounds, char * ciphertext)
{
	return Encryption::EncryptManager::decrypt(EVP_aes_256_cbc(), salt, nrounds, ciphertext);
}
