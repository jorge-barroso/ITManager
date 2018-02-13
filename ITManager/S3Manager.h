#pragma once
#include <aws/core/Aws.h>
#include <aws/s3/S3Client.h>
#include <aws/s3/model/Bucket.h>
#include <aws/s3/model/CreateBucketRequest.h>
#include <aws/s3/model/DeleteBucketRequest.h>
#include <aws/s3/model/HeadBucketRequest.h>
#include <aws/core/auth/AWSCredentialsProvider.h>

namespace AWS
{
	class S3Manager
	{
	public:
		S3Manager(std::string const& accessKey, std::string const& secretAccessKey, std::string const& region);
		~S3Manager();
		bool createBucket(std::string const& bucketName);
		bool cleanupBucket(std::string const& bucketName);
		bool deleteBucket(std::string const& bucketName);
		bool bucketExists(std::string const& bucketName);
		Aws::Vector<Aws::S3::Model::Bucket> getAllBuckets();
		bool renameBucket(std::string const& origName, std::string const& newName);
		//bool downloadObject();
		//bool listObjects();
	private:
		Aws::String regionName;
		Aws::SDKOptions options;
		Aws::S3::S3Client s3Client;
	};
}
