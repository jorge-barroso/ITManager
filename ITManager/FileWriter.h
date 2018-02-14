#pragma once
#include <string>
#include <fstream>
#include <experimental/filesystem>
namespace Files
{
	class FileWriter
		{
		public:
			explicit FileWriter(std::experimental::filesystem::path path, const bool append = false, const bool binary = false);
			explicit FileWriter(std::string const& filename, const bool append = false, const bool binary = false);
			~FileWriter();
			void write(std::string const& value);
			void writeLine(std::string const& line);
		private:
			const std::experimental::filesystem::path path;
			std::ofstream fileStream;
			void openStream(const bool append, const bool binary);
		};
}
