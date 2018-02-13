#include "EncryptManager.h"
#include "openssl/evp.h"
namespace Encryption
{
	class AESEncryptManager :
		public EncryptManager
	{
	public:
		AESEncryptManager(char const*, unsigned char const*, const uint16_t);
		~AESEncryptManager();
		std::string encrypt(const char *);
		std::string decrypt(const char *);
	private:
		unsigned char key[32]{};
		unsigned char iv[32]{};
		EVP_CIPHER_CTX en;
		EVP_CIPHER_CTX de;
	};
}
