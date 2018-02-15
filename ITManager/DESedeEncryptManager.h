#pragma once
#include "EncryptManager.h"
#include "DesWeakKeyException.h"
#include "openssl/des.h"
#include "openssl/rand.h"
#include "Base64.h"
#include <random>
#include <stdexcept>

namespace Encryption
{
	class DESedeEncryptManager :
		public EncryptManager
	{
	public:
		DESedeEncryptManager(const unsigned char *key_data, const unsigned char *salt, const uint16_t nrounds);
	};
}
