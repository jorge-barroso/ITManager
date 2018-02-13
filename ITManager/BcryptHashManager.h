#pragma once
#include "HashManager.h"
namespace Hash
{
	class BcryptHashManager :
		public HashManager
	{
	public:
		BcryptHashManager();
		~BcryptHashManager();
	};
}
