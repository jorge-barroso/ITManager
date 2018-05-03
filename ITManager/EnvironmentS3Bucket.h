#pragma db object
#include "Environment.h"
#include "S3Bucket.h"

#include <odb\core.hxx>

#include <memory>
namespace Models
{
	class EnvironmentS3Bucket
	{
	public:
		EnvironmentS3Bucket(const Models::Environment &environment, const Models::S3Bucket &bucket);
		~EnvironmentS3Bucket();
	private:
		friend class odb::access;
		EnvironmentS3Bucket() {}

		std::shared_ptr<Models::Environment> environment;
		std::shared_ptr<Models::S3Bucket> bucket;
	};
}
