#include "stdafx.h"
#include "AESEncryptManager.h"

inline  uint16_t message_size(const char * key, uint16_t pos)
{
	return (strlen(key) - pos - 1);
}

//TODO test if key data builds the iv and check how to make sure we can decrypt by keeping the iv (if it's built through key_data, just keep key_data)
Encryption::AESEncryptManager::AESEncryptManager(const unsigned char *key_data, const unsigned char *salt, const uint16_t nrounds)
	: Encryption::EncryptManager(EVP_aes_256_cbc(), key_data, salt, nrounds)
{
	/*const int&& i = EVP_BytesToKey(EVP_aes_256_cbc(), EVP_sha1(), salt, key_data, 32, nrounds, this->key, this->iv );

	EVP_CIPHER_CTX_init(&this->en);
	EVP_EncryptInit_ex(&this->en, EVP_aes_256_cbc(), NULL, this->key, this->iv);
	EVP_CIPHER_CTX_init(&this->de);
	EVP_DecryptInit_ex(&this->de, EVP_aes_256_cbc(), NULL, this->key, this->iv);

	std::cout << this->key << std::endl;
	std::cout << this->iv << std::endl;*/
}

/*Encryption::AESEncryptManager::~AESEncryptManager()
{
	EVP_CIPHER_CTX_cleanup(&this->en);

	EVP_CIPHER_CTX_cleanup(&this->de);
}

std::string Encryption::AESEncryptManager::encrypt(const unsigned char * key, uint16_t key_size)
{
	int keyLen = sizeof(key) + 1;
	int cipherLen = keyLen + 256;
	unsigned char * ciphertext = new unsigned char[cipherLen];

	EVP_EncryptInit_ex(&this->en, NULL, NULL, NULL, NULL);

	EVP_EncryptUpdate(&this->en, ciphertext, &cipherLen, key, keyLen);

	EVP_EncryptFinal_ex(&this->en, ciphertext, &cipherLen);

	return Base64::encode(this->iv, sizeof(this->iv)) + this->SPLIT_TOKEN + Base64::encode(ciphertext, cipherLen);
}

std::string Encryption::AESEncryptManager::decrypt(char *key)
{
	const char * iv = strtok(key, &this->SPLIT_TOKEN);

	std::cout << iv << " || " << key << std::endl;
	return "";
}*/