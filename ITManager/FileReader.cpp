#include "stdafx.h"
#include "FileReader.h"
#include <iostream>
Files::FileReader::FileReader(std::experimental::filesystem::path &path) : path(path)
{
	this->openStream();
}

Files::FileReader::FileReader(std::string const& filename) : path(filename)
{
	if (!std::experimental::filesystem::exists(path))
	{
		//TODO exception
	}

	this->openStream();
}

Files::FileReader::~FileReader()
{
	this->fileStream.close();
}

void Files::FileReader::openStream()
{
	this->fileStream = std::ifstream(this->path.c_str());
}

int Files::FileReader::read()
{
	return this->fileStream.get();
}

bool Files::FileReader::readLine(std::string &line)
{
	if (std::getline(this->fileStream, line))
		return true;
	else
		return false;
}

std::string Files::FileReader::readAll()
{
	std::string fileContents;

	this->fileStream.seekg(0, std::ios::end);
	fileContents.resize(this->fileStream.tellg());
	this->fileStream.seekg(0, std::ios::beg);

	this->fileStream.read(&fileContents[0], fileContents.size());

	return fileContents;
}