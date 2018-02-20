#include "stdafx.h"
#include "S3Bucket.h"


Models::S3Bucket::S3Bucket(std::string const& key, const Region region) : key(key), region(region) {}


Models::S3Bucket::~S3Bucket() {}

uint16_t Models::S3Bucket::getId()
{
	return this->id;
}

std::string Models::S3Bucket::getKey()
{
	return this->key;
}

Models::S3Bucket Models::S3Bucket::setKey(std::string const & key)
{
	this->key = key;
	return *this;
}

Region Models::S3Bucket::getRegion()
{
	return this->region;
}
