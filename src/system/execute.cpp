#include <cstdio>
#include <memory>
#include <string>
#include <string_view>
#include <xieite/system/execute.hpp>

std::string xieite::system::execute(const std::string_view command, const std::size_t bufferSize) noexcept {
	decltype([](std::FILE* const file) {
		pclose(file);
	}) closer;
	std::unique_ptr<std::FILE, decltype(closer)> pipe(popen(command.data(), "r"), closer);
	std::string result;
	std::size_t status;
	do {
		std::string buffer(bufferSize, '\0');
		status = std::fread(buffer.data(), sizeof(char), bufferSize, pipe.get());
		result += buffer;
	} while (status);
	return result;
}
