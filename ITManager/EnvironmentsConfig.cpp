#include "stdafx.h"
#include "EnvironmentsConfig.h"

Models::EnvironmentsConfig::EnvironmentsConfig(std::vector<Models::Database> const& databases, std::vector<Models::S3Bucket> const& s3Buckets, std::vector<Models::Instance> const& servers)
	:
	databases(databases),
	s3Buckets(s3Buckets),
	instances(instances)
	{}

Models::EnvironmentsConfig::~EnvironmentsConfig()
{
	free(&this->databases);
	free(&this->s3Buckets);
	free(&this->instances);
}

std::vector<Models::Database> Models::EnvironmentsConfig::getDatabases()
{
	return this->databases;
}

std::vector<Models::S3Bucket> Models::EnvironmentsConfig::getS3Buckets()
{
	return this->s3Buckets;
}

std::vector<Models::Instance> Models::EnvironmentsConfig::getInstances()
{
	return this->instances;
}
