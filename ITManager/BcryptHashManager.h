#pragma once
#include "HashManager.h"
class BcryptHashManager :
	public HashManager
{
public:
	BcryptHashManager();
	~BcryptHashManager();
};

