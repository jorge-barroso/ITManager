#pragma once
#include "EncryptManager.h"
#include "DesWeakKeyException.h"
#include "openssl/des.h"
#include "Base64.h"
#include <random>
#include <stdexcept>

namespace Encryption
{
	class DESedeEncryptManager :
		public EncryptManager
	{
	public:
		DESedeEncryptManager(const char key_data[24], unsigned char const* salt, const uint16_t nrounds);
		~DESedeEncryptManager();
		std::string encrypt(const char * key);
		std::string decrypt(const char *ciphertext);
	private:
		DES_key_schedule *SchKey1, *SchKey2, *SchKey3;
	};
}
