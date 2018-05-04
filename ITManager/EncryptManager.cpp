#include "stdafx.h"
#include "EncryptManager.h"

EVP_CIPHER_CTX Encryption::EncryptManager::de;
EVP_CIPHER_CTX Encryption::EncryptManager::en;
unsigned char Encryption::EncryptManager::key[32];
unsigned char Encryption::EncryptManager::iv[32];

const std::string Encryption::EncryptManager::encrypt(const EVP_CIPHER* cipherMethod, const unsigned char *salt, const uint16_t nrounds, const unsigned char * key, size_t key_size)
{
	std::random_device random;

	Encryption::EncryptManager::init(cipherMethod, salt, reinterpret_cast<const unsigned char *>(std::to_string(random()).c_str()), nrounds);

	std::cout << Base64::encode(Encryption::EncryptManager::key, strlen(reinterpret_cast<const char *>(Encryption::EncryptManager::key))) << std::endl;
	std::cout << Base64::encode(Encryption::EncryptManager::iv, strlen(reinterpret_cast<const char *>(Encryption::EncryptManager::iv))) << std::endl;

	EVP_CIPHER_CTX_init(&Encryption::EncryptManager::en);
	EVP_EncryptInit_ex(&Encryption::EncryptManager::en, cipherMethod, NULL, Encryption::EncryptManager::key, Encryption::EncryptManager::iv);

	int keyLen = sizeof(key) + 1;
	int cipherLen = keyLen + 256;
	unsigned char * ciphertext = new unsigned char[cipherLen];

	EVP_EncryptInit_ex(&Encryption::EncryptManager::en, NULL, NULL, NULL, NULL);

	EVP_EncryptUpdate(&Encryption::EncryptManager::en, ciphertext, &cipherLen, key, keyLen);

	EVP_EncryptFinal_ex(&Encryption::EncryptManager::en, ciphertext, &cipherLen);

	return Base64::encode(Encryption::EncryptManager::iv, sizeof(Encryption::EncryptManager::iv)) + Encryption::EncryptManager::SPLIT_TOKEN + Base64::encode(ciphertext, cipherLen);
}

const std::string Encryption::EncryptManager::decrypt(const EVP_CIPHER* cipherMethod, const unsigned char *salt, const uint16_t nrounds, char * ciphertext)
{
	const char * iv_seed = strtok_s(ciphertext, &Encryption::EncryptManager::SPLIT_TOKEN, new char *);//strtok(ciphertext, &Encryption::EncryptManager::SPLIT_TOKEN);

	std::cout << iv_seed << " || " << ciphertext << std::endl;

	Encryption::EncryptManager::init(cipherMethod, salt, reinterpret_cast<const unsigned char *>(iv_seed), nrounds);

	EVP_CIPHER_CTX_init(&Encryption::EncryptManager::de);
	EVP_DecryptInit_ex(&Encryption::EncryptManager::de, cipherMethod, NULL, Encryption::EncryptManager::key, Encryption::EncryptManager::iv);

	return "";
}

inline const void Encryption::EncryptManager::init(const EVP_CIPHER * cipherMethod, const unsigned char * salt, const unsigned char * iv_seed, const uint16_t nrounds)
{
	EVP_BytesToKey(cipherMethod, EVP_sha1(), salt, iv_seed, 32, nrounds, const_cast<unsigned char *>(Encryption::EncryptManager::key), const_cast<unsigned char *>(Encryption::EncryptManager::iv));
}
