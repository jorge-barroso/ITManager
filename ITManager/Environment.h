#pragma db object
#include <vector>
#include "Instance.h"
#include "S3Bucket.h"
#include "Database.h"
class Environment
{
public:
	Environment(std::vector<Database> const& = std::vector<Database>(3),
				std::vector<S3Bucket> const& = std::vector<S3Bucket>(5),
				std::vector<Instance> const& = std::vector<Instance>(3));

	~Environment();
	std::vector<Database> getDatabases();
	std::vector<S3Bucket> getS3Buckets();
	std::vector<Instance> getInstances();
	
private:
	std::vector<Database> databases;
	std::vector<S3Bucket> s3Buckets;
	std::vector<Instance> instances;
};

