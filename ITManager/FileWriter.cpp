#include "stdafx.h"
#include "FileWriter.h"

FileWriter::FileWriter(std::experimental::filesystem::path path, const bool append, const bool binary) : path(path)
{
	this->openStream(append, binary);
}

FileWriter::FileWriter(std::string const & filename, const bool append, const bool binary) : path(filename)
{
	this->openStream(append, binary);
}


FileWriter::~FileWriter()
{
	this->fileStream.close();
}

void FileWriter::write(std::string const& value)
{
	this->fileStream << value;
}

void FileWriter::writeLine(std::string const& line)
{
	this->fileStream << line << std::endl;
}

void FileWriter::openStream(const bool append, const bool binary)
{
	if(append && binary)
		this->fileStream = std::ofstream(this->path.c_str(), std::ofstream::app|std::ofstream::binary);
	else if(append)
		this->fileStream = std::ofstream(this->path.c_str(), std::ofstream::app);
	else if (binary)
		this->fileStream = std::ofstream(this->path.c_str(), std::ofstream::binary);
	else
		this->fileStream = std::ofstream(this->path.c_str());
}
