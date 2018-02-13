#include "stdafx.h"
#include "Environment.h"

Environment::Environment(std::vector<Database> const& databases, std::vector<S3Bucket> const& s3Buckets, std::vector<Instance> const& servers)
{
	this->databases = databases;
	this->s3Buckets = s3Buckets;
	this->instances = servers;
}

Environment::~Environment()
{
	free(&this->databases);
	free(&this->s3Buckets);
	free(&this->instances);
}

std::vector<Database> Environment::getDatabases()
{
	return this->databases;
}

std::vector<S3Bucket> Environment::getS3Buckets()
{
	return this->s3Buckets;
}

std::vector<Instance> Environment::getInstances()
{
	return this->instances;
}
