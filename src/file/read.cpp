
#include <fstream>
#include <gcufl/file/read.hpp>
#include <iterator>


std::string gcufl::file::read(const std::string& path) noexcept {
	std::ifstream reader(path);
	return std::string(std::istreambuf_iterator<char>(reader), std::istreambuf_iterator<char>());
}
