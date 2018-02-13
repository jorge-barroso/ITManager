#pragma once
#include <string>
#include <experimental/filesystem>
#include <fstream>
class FileReader
{
public:
	FileReader(std::experimental::filesystem::path &path);
	FileReader(std::string const& fileName);
	~FileReader();
	int read();
	bool readLine(std::string &line);
	std::string readAll();
private:
	const std::experimental::filesystem::path path;
	std::ifstream fileStream;
	void openStream();
};

