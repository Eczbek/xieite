#include <cstdio>
#include <string>
#include <string_view>
#include <xieite/system/execute.hpp>

std::string xieite::system::execute(const std::string_view command, const std::size_t bufferSize) noexcept {
	std::FILE* file = popen(command.data(), "r");
	std::string result;
	std::size_t status;
	do {
		std::string buffer(bufferSize, '\0');
		status = std::fread(buffer.data(), sizeof(char), bufferSize, file);
		result += buffer;
	} while (status);
	pclose(file);
	return result;
}
