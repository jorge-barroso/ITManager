#include "stdafx.h"
#include "S3Bucket.h"


S3Bucket::S3Bucket(std::string const& key, uint16_t const id = 0)
{
	this->id = id;
	this->key = key;

}


S3Bucket::~S3Bucket()
{
}

uint16_t S3Bucket::getId()
{
	return this->id;
}

std::string S3Bucket::getKey()
{
	return this->key;
}
