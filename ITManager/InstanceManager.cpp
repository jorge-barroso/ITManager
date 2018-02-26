#include "stdafx.h"
#include "InstanceManager.h"


InstanceManager::InstanceManager(std::string const & accessKey, std::string const & secretAccessKey, Regions::Region const & region)
	:
	regionName(Aws::Utils::StringUtils::to_string(Regions::getRegionName(region)))
{
	Aws::InitAPI(this->options);
	//this->s3Client = Aws::S3::S3Client(Aws::Auth::AWSCredentials(accessKey, secretAccessKey));
	Aws::Client::ClientConfiguration config;
	config.region = this->regionName;

	this->ec2Client = Aws::EC2::EC2Client(Aws::Auth::AWSCredentials(Aws::Utils::StringUtils::to_string(accessKey), Aws::Utils::StringUtils::to_string(accessKey)), config);
}

InstanceManager::~InstanceManager(){}

std::string InstanceManager::createInstance(const std::string &name, const Aws::EC2::Model::InstanceType instanceType)
{
	const Aws::String &instanceName = Aws::Utils::StringUtils::to_string(name);

	Aws::EC2::Model::RunInstancesRequest runRequest;
	runRequest.SetInstanceType(instanceType);
	runRequest.SetMinCount(1);
	runRequest.SetMaxCount(1);

	Aws::EC2::Model::RunInstancesOutcome response = this->ec2Client.RunInstances(runRequest);

	if (response.IsSuccess())
	{
		throw std::exception(("Failed to create instance " + instanceName + ":" + response.GetError().GetMessage()).c_str());
	}

	const Aws::Vector<Aws::EC2::Model::Instance> instances = response.GetResult().GetInstances();
	if (instances.size() == 0)
	{
		throw std::exception(("Failed to create instance " + instanceName + ":" + response.GetError().GetMessage()).c_str());
	}

	//Now apply name
	Aws::EC2::Model::Tag nameTag;
	nameTag.SetKey("Name");
	nameTag.SetValue(instanceName);

	const Aws::String &instanceId = instances[0].GetInstanceId();
	Aws::EC2::Model::CreateTagsRequest tagsRequest;
	tagsRequest.AddResources(instanceId);
	tagsRequest.AddTags(nameTag);

	Aws::EC2::Model::CreateTagsOutcome tagsOutcome = this->ec2Client.CreateTags(tagsRequest);
	if (!tagsOutcome.IsSuccess())
	{
		throw std::exception(("Failed to name instance " + instanceId + ":" + tagsOutcome.GetError().GetMessage()).c_str());
	}

	return instanceId.c_str();
}

void InstanceManager::startInstance(Models::Instance instance)
{
	const Aws::String&& instanceId = Aws::Utils::StringUtils::to_string(instance.getInstanceId());
	Aws::EC2::Model::StartInstancesRequest startRequest;
	startRequest.AddInstanceIds(instanceId);

	//dry run to check possible permission problems
	startRequest.SetDryRun(true);
	const Aws::EC2::Model::StartInstancesOutcome&& permissionRequestOutcome = this->ec2Client.StartInstances(startRequest);

	if (permissionRequestOutcome.GetError().GetErrorType() != Aws::EC2::EC2Errors::DRY_RUN_OPERATION)
	{
		throw std::exception(("Failed to start instance " + instanceId + ":" + permissionRequestOutcome.GetError().GetMessage()).c_str());
	}

	//real run to start instance
	startRequest.SetDryRun(false);
	const Aws::EC2::Model::StartInstancesOutcome&& finalRequestOutcome = this->ec2Client.StartInstances(startRequest);
	if (!finalRequestOutcome.IsSuccess())
	{
		throw std::exception(("Failed to start instance " + instanceId + ":" + finalRequestOutcome.GetError().GetMessage()).c_str());
	}

}

void InstanceManager::stopInstance(Models::Instance instance)
{
	const Aws::String&& instanceId = Aws::Utils::StringUtils::to_string(instance.getInstanceId());
	Aws::EC2::Model::StopInstancesRequest stopRequest;
	stopRequest.AddInstanceIds(instanceId);

	//dry run to check possible permission problems
	stopRequest.SetDryRun(true);
	const Aws::EC2::Model::StopInstancesOutcome&& permissionRequestOutcome = this->ec2Client.StopInstances(stopRequest);

	if (permissionRequestOutcome.GetError().GetErrorType() != Aws::EC2::EC2Errors::DRY_RUN_OPERATION)
	{
		throw std::exception(("Failed to stop instance " + instanceId + ":" + permissionRequestOutcome.GetError().GetMessage()).c_str());
	}

	//real run to start instance
	stopRequest.SetDryRun(false);
	const Aws::EC2::Model::StopInstancesOutcome&& finalRequestOutcome = this->ec2Client.StopInstances(stopRequest);
	if (!finalRequestOutcome.IsSuccess())
	{
		throw std::exception(("Failed to stop instance " + instanceId + ":" + finalRequestOutcome.GetError().GetMessage()).c_str());
	}
}

void InstanceManager::rebootInstance(Models::Instance instance)
{
	const Aws::String&& instanceId = Aws::Utils::StringUtils::to_string(instance.getInstanceId());
	Aws::EC2::Model::RebootInstancesRequest rebootRequest;
	rebootRequest.AddInstanceIds(instanceId);

	//dry run to check possible permission problems
	rebootRequest.SetDryRun(true);
	const Aws::EC2::Model::RebootInstancesOutcome&& permissionRequestOutcome = this->ec2Client.RebootInstances(rebootRequest);

	if (permissionRequestOutcome.GetError().GetErrorType() != Aws::EC2::EC2Errors::DRY_RUN_OPERATION)
	{
		throw std::exception(("Failed to reboot instance " + instanceId + ":" + permissionRequestOutcome.GetError().GetMessage()).c_str());
	}

	//real run to start instance
	rebootRequest.SetDryRun(false);
	const Aws::EC2::Model::RebootInstancesOutcome&& finalRequestOutcome = this->ec2Client.RebootInstances(rebootRequest);
	if (!finalRequestOutcome.IsSuccess())
	{
		throw std::exception(("Failed to reboot instance " + instanceId + ":" + finalRequestOutcome.GetError().GetMessage()).c_str());
	}
}
