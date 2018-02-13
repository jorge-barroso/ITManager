#pragma once
#include <iostream>
class Base64
{
public:
	static std::string encode(unsigned char const*, unsigned int);
	static std::string decode(std::string const&);
private:
	static inline bool is_base64(unsigned char c);
};

