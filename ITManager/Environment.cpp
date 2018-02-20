#include "stdafx.h"
#include "Environment.h"

Models::Environment::Environment(std::vector<Models::Database> const& databases, std::vector<Models::S3Bucket> const& s3Buckets, std::vector<Models::Instance> const& servers)
	:
	databases(databases),
	s3Buckets(s3Buckets),
	instances(instances)
	{}

Models::Environment::~Environment()
{
	free(&this->databases);
	free(&this->s3Buckets);
	free(&this->instances);
}

std::vector<Models::Database> Models::Environment::getDatabases()
{
	return this->databases;
}

std::vector<Models::S3Bucket> Models::Environment::getS3Buckets()
{
	return this->s3Buckets;
}

std::vector<Models::Instance> Models::Environment::getInstances()
{
	return this->instances;
}
