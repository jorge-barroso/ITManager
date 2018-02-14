#pragma once
#include <string>
#include <experimental/filesystem>
#include <fstream>
namespace Files
{
	class FileReader
	{
	public:
		explicit FileReader(std::experimental::filesystem::path &path);
		explicit FileReader(std::string const& fileName);
		~FileReader();
		int read();
		bool readLine(std::string &line);
		std::string readAll();
	private:
		const std::experimental::filesystem::path path;
		std::ifstream fileStream;
		void openStream();
	};
}

