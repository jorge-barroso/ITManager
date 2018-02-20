#include "stdafx.h"
#include "InstanceManager.h"


InstanceManager::InstanceManager(std::string const & accessKey, std::string const & secretAccessKey, std::string const & region) : regionName(Aws::Utils::StringUtils::to_string(region))
{
	Aws::InitAPI(this->options);
	//this->s3Client = Aws::S3::S3Client(Aws::Auth::AWSCredentials(accessKey, secretAccessKey));
	Aws::Client::ClientConfiguration config;
	config.region = this->regionName;

	this->ec2Client = Aws::EC2::EC2Client(Aws::Auth::AWSCredentials(Aws::Utils::StringUtils::to_string(accessKey), Aws::Utils::StringUtils::to_string(accessKey)), config);
}

InstanceManager::~InstanceManager(){}
