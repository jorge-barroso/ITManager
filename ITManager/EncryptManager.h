#pragma once
#include <string>
#include <random>
#include <functional>
#include "openssl/evp.h"
#include "Base64.h"

namespace Encryption
{
	class EncryptManager
	{
	public:
		static const std::string encrypt(const EVP_CIPHER* cipherMethod, const unsigned char *salt, const uint16_t nrounds, const unsigned char * key, size_t key_size);
		static const std::string decrypt(const EVP_CIPHER* cipherMethod, const unsigned char *salt, const uint16_t nrounds, char * ciphertext);
	private:
		static const inline void init(const EVP_CIPHER* cipherMethod, const unsigned char *salt, const unsigned char* iv_seed, const uint16_t nrounds);
		static unsigned char key[32];
		static unsigned char iv[32];
		static EVP_CIPHER_CTX en;
		static EVP_CIPHER_CTX de;
	protected:
		static const char SPLIT_TOKEN = ':';
	};
}
