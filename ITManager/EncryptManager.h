#pragma once
#include <string>
#include "openssl/evp.h"
#include "Base64.h"

namespace Encryption
{
	class EncryptManager
	{
	public:
		explicit EncryptManager(const EVP_CIPHER* cipherMethod, const unsigned char *key_data, const unsigned char *salt, const uint16_t nrounds);
		virtual~EncryptManager() = 0;
		std::string encrypt(const unsigned char * key, uint16_t key_size);
		std::string decrypt(char * ciphertext);
	private:
		unsigned char key[32]{};
		unsigned char iv[32]{};
		EVP_CIPHER_CTX en;
		EVP_CIPHER_CTX de;
	protected:
		const char SPLIT_TOKEN = ':';
	};
}
