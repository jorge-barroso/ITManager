#pragma once
#include <string>
namespace Hash
{
	class HashManager
	{
	public:
		HashManager();
		~HashManager();
		virtual std::string hash() = 0;
		virtual bool matches() = 0;
	};
}
