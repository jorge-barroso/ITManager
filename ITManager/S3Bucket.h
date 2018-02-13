#pragma once
#include <cstdint>
#include <string>
class S3Bucket
{
public:
	S3Bucket(std::string const&, uint16_t const);
	~S3Bucket();
	uint16_t getId();
	std::string getKey();
private:
	uint16_t id;
	std::string key;
};

