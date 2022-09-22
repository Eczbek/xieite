
#include <fstream>
#include <gcufl/files/read.hpp>
#include <iterator>


std::string gcufl::files::read(const std::string& path) noexcept {
	std::ifstream reader(path);
	return std::string(std::istreambuf_iterator<char>(reader), std::istreambuf_iterator<char>());
}
