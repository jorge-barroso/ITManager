#include "stdafx.h"
#include "DESedeEncryptManager.h"


Encryption::DESedeEncryptManager::DESedeEncryptManager(char const* key_data, unsigned char const* salt, const uint16_t nrounds)
{
	char cKey1[8];
	char cKey2[8];
	char cKey3[8];

	for (uint16_t i = 0; i < 24; i++)
	{
		uint16_t j = 0;

		if (i % 3 == 0)
			cKey3[i / 3] = key_data[i];
		else if (i % 2 == 0)
			cKey2[i / 2] = key_data[i];
		else
			cKey1[j++] = key_data[i];
	}
}


Encryption::DESedeEncryptManager::~DESedeEncryptManager()
{
}
