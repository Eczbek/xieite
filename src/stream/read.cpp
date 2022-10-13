
#include <cstdio>
#include <fstream>
#include <gcufl/stream/read.hpp>
#include <iterator>
#include <memory>
#include <string>
#include <string_view>
#include <type_traits>

std::string gcufl::stream::read(std::istream& reader) noexcept {
	return std::string(std::istreambuf_iterator<char>(reader), std::istreambuf_iterator<char>());
}

std::string gcufl::stream::read(std::FILE* const file) noexcept {
	std::unique_ptr<std::FILE, decltype(&pclose)> pipe(file, pclose);
	std::string result;
	if (pipe) {
		const int bufferSize = 1024;
		std::string buffer(bufferSize, '\0');
		char* const bufferData = buffer.data();
		while (std::fgets(bufferData, bufferSize, pipe.get()) != nullptr)
			result += buffer;
	}
	return result;
}
