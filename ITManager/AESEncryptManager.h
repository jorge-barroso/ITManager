#include "EncryptManager.h"

namespace Encryption
{
	class AESEncryptManager :
		public EncryptManager
	{
	public:
		static const std::string encrypt(const unsigned char *salt, const uint16_t nrounds, const unsigned char * key, size_t key_size);
		static const std::string decrypt(const unsigned char *salt, const uint16_t nrounds, char * ciphertext);
	};
}
