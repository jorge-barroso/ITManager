#pragma once
#include "EncryptManager.h"
namespace Encryption
{
	class DESedeEncryptManager :
		public EncryptManager
	{
	public:
		DESedeEncryptManager(char const* key_data, unsigned char const* salt, const uint16_t nrounds);
		~DESedeEncryptManager();
	};
}
