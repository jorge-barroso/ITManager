#pragma once
#include "aws/core/Aws.h"
#include "aws/ec2/EC2Client.h"
#include "aws/core/auth/AWSCredentialsProvider.h"
class InstanceManager
{
public:
	InstanceManager(std::string const& accessKey, std::string const& secretAccessKey, std::string const& region);
	~InstanceManager();
	void createInstance(const Aws::EC2::Model::InstanceType instanceType);
	void startInstance();
	void stopdInstance();
	void rebootInstance();
private:
	Aws::EC2::EC2Client ec2Client;
	Aws::SDKOptions options;
	Aws::String regionName;
};

