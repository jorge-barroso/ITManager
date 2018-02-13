#include "stdafx.h"
#include "FileReader.h"
#include <iostream>
FileReader::FileReader(std::experimental::filesystem::path &path) : path(path)
{
	this->openStream();
}

FileReader::FileReader(std::string const& filename) : path(filename)
{
	if (!std::experimental::filesystem::exists(path))
	{
		//TODO exception
	}

	this->openStream();
}

FileReader::~FileReader()
{
	this->fileStream.close();
}

void FileReader::openStream()
{
	this->fileStream = std::ifstream(this->path.c_str());
}

int FileReader::read()
{
	return this->fileStream.get();
}

bool FileReader::readLine(std::string &line)
{
	if (std::getline(this->fileStream, line))
		return true;
	else
		return false;
}

std::string FileReader::readAll()
{
	std::string fileContents;

	this->fileStream.seekg(0, std::ios::end);
	fileContents.resize(this->fileStream.tellg());
	this->fileStream.seekg(0, std::ios::beg);

	this->fileStream.read(&fileContents[0], fileContents.size());

	return fileContents;
}