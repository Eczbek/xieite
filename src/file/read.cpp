
#include <fstream>
#include <gcufl/file/read.hpp>
#include <iterator>
#include <string>
#include <string_view>


std::string gcufl::file::read(const std::string_view path) noexcept {
	std::ifstream reader(path.data());
	return std::string(std::istreambuf_iterator<char>(reader), std::istreambuf_iterator<char>());
}
