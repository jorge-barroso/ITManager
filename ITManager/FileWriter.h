#pragma once
#include <string>
#include <fstream>
#include <experimental/filesystem>
class FileWriter
{
public:
	FileWriter(std::experimental::filesystem::path path, const bool append = false, const bool binary = false);
	FileWriter(std::string const& filename, const bool append = false, const bool binary = false);
	~FileWriter();
	void write(std::string const& value);
	void writeLine(std::string const& line);
private:
	std::experimental::filesystem::path path;
	std::ofstream fileStream;
	void openStream(const bool append, const bool binary);
};

