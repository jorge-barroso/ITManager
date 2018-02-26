#include "stdafx.h"
#include "S3Manager.h"


AWS::S3Manager::S3Manager(std::string const& accessKey, std::string const& secretAccessKey, Regions::Region const& region) : regionName(Aws::Utils::StringUtils::to_string(Regions::getRegionName(region)))
{
	Aws::InitAPI(this->options);
	//this->s3Client = Aws::S3::S3Client(Aws::Auth::AWSCredentials(accessKey, secretAccessKey));
	Aws::Client::ClientConfiguration config;
	config.region = this->regionName;
	this->s3Client = Aws::S3::S3Client(Aws::Auth::AWSCredentials(Aws::Utils::StringUtils::to_string(accessKey), Aws::Utils::StringUtils::to_string(secretAccessKey)), config);
}


AWS::S3Manager::~S3Manager()
{
	Aws::ShutdownAPI(this->options);
}

bool AWS::S3Manager::createBucket(std::string const & bucketName)
{
	/* TODO recover if main S3Client config doesn't work 
		//create a configuration object to store the region
		Aws::S3::Model::CreateBucketConfiguration configuration;
		configuration.SetLocationConstraint(Aws::S3::Model::BucketLocationConstraintMapper::GetBucketLocationConstraintForName(this->regionName));
	*/

	//create and configure the request
	Aws::S3::Model::CreateBucketRequest request;
	const Aws::String&& bucket = Aws::Utils::StringUtils::to_string(bucketName);
	request.SetBucket(bucket);
	// TODO allow to make public request.SetGrantRead();
	// TODO recover if main S3Client config doesn't work request.SetCreateBucketConfiguration(configuration);

	//produce request and store result
	Aws::S3::Model::CreateBucketOutcome const&& outcome = this->s3Client.CreateBucket(request);

	return outcome.IsSuccess();
}

bool AWS::S3Manager::cleanupBucket(std::string const & bucketName)
{

	return false;
}

bool AWS::S3Manager::deleteBucket(std::string const & bucketName)
{
	const Aws::String&& bucket = Aws::Utils::StringUtils::to_string(bucketName);

	Aws::S3::Model::DeleteBucketOutcome const&& outcome = this->s3Client.DeleteBucket(Aws::S3::Model::DeleteBucketRequest().WithBucket(bucket));

	return outcome.IsSuccess();
}

bool AWS::S3Manager::bucketExists(std::string const& bucketName)
{
	Aws::S3::Model::HeadBucketRequest request;

	const Aws::String&& bucket = Aws::Utils::StringUtils::to_string(bucketName);

	request.SetBucket(bucket);

	Aws::S3::Model::HeadBucketOutcome outcome = this->s3Client.HeadBucket(request);

	return outcome.IsSuccess();
}

Aws::Vector<Aws::S3::Model::Bucket> AWS::S3Manager::getAllBuckets()
{
	Aws::S3::Model::ListBucketsOutcome const&& outcome = this->s3Client.ListBuckets();
	return outcome.GetResult().GetBuckets();
}

bool AWS::S3Manager::renameBucket(std::string const& origName, std::string const& newName)
{
	return false;
}
