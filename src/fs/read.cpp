
#include <fstream>
#include <gcufl/fs/read.hpp>
#include <iterator>


std::string gcufl::fs::read(const std::string& path) noexcept {
	std::ifstream reader(path);
	return std::string(std::istreambuf_iterator<char>(reader), {});
}
