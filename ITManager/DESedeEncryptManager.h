#pragma once
#include "EncryptManager.h"
namespace Encryption
{
	class DESedeEncryptManager :
		public EncryptManager
	{
	public:
		DESedeEncryptManager();
		~DESedeEncryptManager();
	};
}
