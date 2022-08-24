#include <gcufl/fs.hpp>
#include <fstream>
#include <iterator>


std::string gcufl::fs::read(const std::string& path) noexcept {
	std::ifstream reader(path);
	return std::string(std::istreambuf_iterator<char>(reader), {});
}
