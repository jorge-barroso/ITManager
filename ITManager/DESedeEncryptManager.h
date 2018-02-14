#pragma once
#include "EncryptManager.h"
#include "openssl/des.h"
#include <random>
#include <stdexcept>

namespace Encryption
{
	class DESedeEncryptManager :
		public EncryptManager
	{
	public:
		DESedeEncryptManager(char const* key_data, unsigned char const* salt, const uint16_t nrounds);
		~DESedeEncryptManager();
		std::string encrypt(const char *);
		std::string decrypt(const char *);
	private:
		DES_key_schedule *SchKey1, *SchKey2, *SchKey3;
	};
}
