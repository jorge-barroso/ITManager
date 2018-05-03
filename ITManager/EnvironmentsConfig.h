#pragma db object
#include <vector>
#include "Instance.h"
#include "S3Bucket.h"
#include "Database.h"
#include "odb\core.hxx"
namespace Models
{
	class EnvironmentsConfig
	{
	public:
		EnvironmentsConfig(Models::Database const& = Models::Database,
						   Models::S3Bucket const& = Models::S3Bucket,
						   Models::Instance const& = Models::Instance);

		~EnvironmentsConfig();

		Models::Database getDatabases();
		Models::S3Bucket getS3Buckets();
		Models::Instance getInstances();

	private:
		friend class odb::access;
		EnvironmentsConfig() {}

		Models::Database databases;
		Models::S3Bucket s3Buckets;
		Models::Instance instances;
	};
}
