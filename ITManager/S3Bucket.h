#pragma db object
#include <cstdint>
#include <string>
#include "odb\core.hxx"
#include "Regions.h"
namespace Models
{
	class S3Bucket
	{
	public:
		S3Bucket(std::string const& key, const Regions::Region region);
		~S3Bucket();

		uint16_t getId();

		std::string getKey();
		Models::S3Bucket setKey(std::string const& key);

		Regions::Region getRegion();
	private:

		friend class odb::access;
		S3Bucket() {}

		#pragma db id
		uint16_t id;

		std::string key;

		Regions::Region region;
	};
}
