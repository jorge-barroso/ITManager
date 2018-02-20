#pragma db object
#include <vector>
#include "Instance.h"
#include "S3Bucket.h"
#include "Database.h"
#include "odb\core.hxx"
namespace Models
{
	class Environment
	{
	public:
		Environment(std::vector<Models::Database> const& = std::vector<Models::Database>(3),
			std::vector<Models::S3Bucket> const& = std::vector<Models::S3Bucket>(5),
			std::vector<Models::Instance> const& = std::vector<Models::Instance>(3));

		~Environment();
		std::vector<Models::Database> getDatabases();
		std::vector<Models::S3Bucket> getS3Buckets();
		std::vector<Models::Instance> getInstances();

	private:
		friend class odb::access;
		Environment() {}

		std::vector<Models::Database> databases;
		std::vector<Models::S3Bucket> s3Buckets;
		std::vector<Models::Instance> instances;
	};
}
