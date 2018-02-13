#pragma once
#include <string>
#include "EncAlgorithm.h"
class EncryptManager
{
public:
	EncryptManager();
	virtual~EncryptManager() = 0;
	virtual std::string encrypt(const char *) = 0;
	virtual std::string decrypt(const char *) = 0;
private:
	unsigned char key;
	unsigned char iv;
};

