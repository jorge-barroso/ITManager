#include "stdafx.h"
#include "Base64.h"
#include "AESEncryptManager.h"
#include <iostream>

inline  uint16_t message_size(const char * key, uint16_t pos)
{
	return (strlen(key) - pos - 1);
}

//TODO test if key data builds the iv and check how to make sure we can decrypt by keeping the iv (if it's built through key_data, just keep key_data)
Encryption::AESEncryptManager::AESEncryptManager(char const* key_data, unsigned char const* salt, const uint16_t nrounds)
{
	int i = EVP_BytesToKey(EVP_aes_256_cbc(), EVP_sha1(), salt, (unsigned char *)key_data, strlen(key_data), nrounds, this->key, this->iv );

	EVP_CIPHER_CTX_init(&this->en);
	EVP_EncryptInit_ex(&this->en, EVP_aes_256_cbc(), NULL, this->key, this->iv);
	EVP_CIPHER_CTX_init(&this->de);
	EVP_DecryptInit_ex(&this->de, EVP_aes_256_cbc(), NULL, this->key, this->iv);

	std::cout << this->key << std::endl;
	std::cout << this->iv << std::endl;
}

Encryption::AESEncryptManager::~AESEncryptManager()
{
	EVP_CIPHER_CTX_cleanup(&this->en);

	EVP_CIPHER_CTX_cleanup(&this->de);
}

std::string Encryption::AESEncryptManager::encrypt(const char *key)
{
	int keyLen = strlen(key) + 1;
	int cipherLen = keyLen + 256;
	unsigned char *ciphertext = (unsigned char*)malloc(cipherLen);

	EVP_EncryptInit_ex(&this->en, NULL, NULL, NULL, NULL);

	EVP_EncryptUpdate(&this->en, ciphertext, &cipherLen, (unsigned char *)key, keyLen);

	EVP_EncryptFinal_ex(&this->en, ciphertext, &cipherLen);

	return Base64::encode(this->iv, strlen((const char *)this->iv))+":"+Base64::encode(ciphertext, cipherLen);
}

std::string Encryption::AESEncryptManager::decrypt(const char *key)
{
	const uint16_t pos = (uint16_t)strchr(key, ':');

	char * iv = new char[pos + 1];
	strncpy_s(iv, pos + 1, key, 0);

	char * message = new char[message_size(key, pos)];
	strncpy_s(message, message_size(key, pos), key, pos+1);

	std::cout << iv << " || " << message << std::endl;
	return "";
}