#include "EncryptManager.h"

namespace Encryption
{
	class AESEncryptManager :
		public EncryptManager
	{
	public:
		AESEncryptManager(const unsigned char *key_data, const unsigned char *salt, const uint16_t nrounds);
	};
}
