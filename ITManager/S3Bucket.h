#pragma db object
#include <cstdint>
#include <string>
#include "odb\core.hxx"
class S3Bucket
{
public:
	S3Bucket(std::string const&, uint16_t const);
	~S3Bucket();
	uint16_t id();
	std::string key();
private:

	friend class odb::access;
	S3Bucket() {}

	#pragma db id
	uint16_t id;
	std::string key;
};

