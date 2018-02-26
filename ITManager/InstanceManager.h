#pragma once
#include "aws/core/Aws.h"
#include "aws/ec2/EC2Client.h"
#include "aws/core/auth/AWSCredentialsProvider.h"
#include "aws/ec2/model/StartInstancesRequest.h"
#include "aws/ec2/model/StopInstancesRequest.h"
#include "aws/ec2/model/RunInstancesRequest.h"
#include "aws/ec2/model/CreateTagsRequest.h"
#include "aws/ec2/model/RebootInstancesRequest.h"
#include "aws/ec2/model/Instance.h"
#include "aws/ec2/model/Tag.h"
#include "Instance.h"
#include "Regions.h"

class InstanceManager
{
public:
	InstanceManager(std::string const& accessKey, std::string const& secretAccessKey, Regions::Region const& region);
	~InstanceManager();
	std::string createInstance(const std::string &name, Aws::EC2::Model::InstanceType instanceType);
	void startInstance(Models::Instance instance);
	void stopInstance(Models::Instance instance);
	void rebootInstance(Models::Instance instance);
private:
	Aws::EC2::EC2Client ec2Client;
	Aws::SDKOptions options;
	Aws::String regionName;
};

