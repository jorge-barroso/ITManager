#include "stdafx.h"
#include "DESedeEncryptManager.h"
#include "openssl/evp.h"

Encryption::DESedeEncryptManager::DESedeEncryptManager(const unsigned char *key_data, const unsigned char *salt, const uint16_t nrounds)
	: Encryption::EncryptManager(EVP_des_ede3_cbc(), key_data, salt, nrounds)
{}
	/*if (strlen(key_data) < 24)
		throw new std::length_error("Your key should be at least 24 characters long");

	DES_cblock cKey1;// = { key_data[0], key_data[3], key_data[6], key_data[9], key_data[12], key_data[15], key_data[18], key_data[21] };
	DES_cblock cKey2;// = { key_data[1], key_data[4], key_data[7], key_data[10], key_data[13], key_data[16], key_data[19], key_data[22] };
	DES_cblock cKey3;// = { key_data[2], key_data[5], key_data[8], key_data[11], key_data[14], key_data[17], key_data[20], key_data[23] };

	const char * dataPtr = key_data;
	const char * dataPtr2 = dataPtr + 7;
	const char * dataPtr3 = dataPtr2 + 7;

	memcpy(&cKey1, dataPtr, 8);
	memcpy(&cKey2, dataPtr2, 8);
	memcpy(&cKey3, dataPtr3, 8);

	if ((DES_set_key_checked(&cKey1, this->SchKey1) || DES_set_key_checked(&cKey2, this->SchKey2) || DES_set_key_checked(&cKey3, this->SchKey3)) == -2)
	{
		throw new DesWeakKeyException("The key password is too weak");
	}
}

Encryption::DESedeEncryptManager::~DESedeEncryptManager()
{
	free(this->SchKey1);
	free(this->SchKey2);
	free(this->SchKey3);

	delete this->SchKey1;
	delete this->SchKey2;
	delete this->SchKey3;
}

std::string Encryption::DESedeEncryptManager::encrypt(const unsigned char * key, uint16_t key_size)
{
	DES_cblock iv;

	RAND_bytes(iv, 8);

	DES_set_odd_parity(&iv);

	unsigned char *ciphertext = new unsigned char[key_size];

	DES_ede3_cbc_encrypt(key, ciphertext, key_size, this->SchKey1, this->SchKey2, this->SchKey3, &iv, DES_ENCRYPT);

	return Base64::encode(iv, 8) + ":" + Base64::encode(ciphertext, key_size);
}

std::string Encryption::DESedeEncryptManager::decrypt(char * ciphertext)
{
	std::string const&& sIv = Base64::decode(std::string(strtok(ciphertext, (const char *)':')));

	DES_cblock iv;

	memcpy(&iv, &sIv, 8);

	DES_set_odd_parity(&iv);

	const size_t cipherSize = sizeof(ciphertext);
	unsigned char text[cipherSize];

	DES_ede3_cbc_encrypt(reinterpret_cast<const unsigned char *>(const_cast<const char *>(ciphertext)), text, cipherSize, this->SchKey1, this->SchKey2, this->SchKey3, &iv, DES_DECRYPT);

	return std::string(reinterpret_cast<char *>(text));
}*/
