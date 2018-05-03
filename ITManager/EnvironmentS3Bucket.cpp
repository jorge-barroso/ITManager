#include "stdafx.h"
#include "EnvironmentS3Bucket.h"


Models::EnvironmentS3Bucket::EnvironmentS3Bucket(const Models::Environment & environment, const Models::S3Bucket & bucket)
	:
	environment(std::make_shared<Models::Environment>(environment)),
	bucket(std::make_shared<Models::S3Bucket>(bucket))
{
}

Models::EnvironmentS3Bucket::~EnvironmentS3Bucket()
{
}
