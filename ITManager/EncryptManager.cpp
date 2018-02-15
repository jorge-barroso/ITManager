#include "stdafx.h"
#include "EncryptManager.h"
#include <iostream>

Encryption::EncryptManager::EncryptManager(const EVP_CIPHER* const unsigned char *key_data, const unsigned char *salt, const uint16_t nrounds)
{
	const int&& i = EVP_BytesToKey(cipherMethod, EVP_sha1(), salt, key_data, 32, nrounds, this->key, this->iv);

	EVP_CIPHER_CTX_init(&this->en);
	EVP_EncryptInit_ex(&this->en, cipherMethod, NULL, this->key, this->iv);
	EVP_CIPHER_CTX_init(&this->de);
	EVP_DecryptInit_ex(&this->de, cipherMethod, NULL, this->key, this->iv);

	std::cout << this->key << std::endl;
	std::cout << this->iv << std::endl;
}

Encryption::EncryptManager::~EncryptManager()
{
}

std::string Encryption::EncryptManager::encrypt(const unsigned char * key, uint16_t key_size)
{
	int keyLen = sizeof(key) + 1;
	int cipherLen = keyLen + 256;
	unsigned char * ciphertext = new unsigned char[cipherLen];

	EVP_EncryptInit_ex(&this->en, NULL, NULL, NULL, NULL);

	EVP_EncryptUpdate(&this->en, ciphertext, &cipherLen, key, keyLen);

	EVP_EncryptFinal_ex(&this->en, ciphertext, &cipherLen);

	return Base64::encode(this->iv, sizeof(this->iv)) + this->SPLIT_TOKEN + Base64::encode(ciphertext, cipherLen);
}

std::string Encryption::EncryptManager::decrypt(char * ciphertext)
{
	const char * iv = strtok(ciphertext, &this->SPLIT_TOKEN);

	std::cout << iv << " || " << key << std::endl;
	return "";
}
