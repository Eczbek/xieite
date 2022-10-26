
#include <cstdio>
#include <gcufl/stream/readFile.hpp>
#include <memory>
#include <string>

std::string gcufl::stream::readFile(std::FILE* const file) noexcept {
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
