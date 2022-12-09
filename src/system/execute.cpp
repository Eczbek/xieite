#include <cstddef> // std::size_t
#include <cstdio> // pclose, popen, std::FILE, std::fread
#include <memory> // std::unique_ptr
#include <string> // std::string
#include <string_view> // std::string_view
#include <xieite/system/execute.hpp>

std::string xieite::system::execute(const std::string_view command, const std::size_t chunkSize) noexcept {
	decltype([](std::FILE* const file) {
		pclose(file);
	}) closer;
	std::unique_ptr<std::FILE, decltype(closer)> pipe(popen(command.data(), "r"), closer);
	std::string buffer;
	std::size_t status;
	do {
		std::string chunk(chunkSize, '\0');
		status = std::fread(chunk.data(), sizeof(char), chunkSize, pipe.get());
		buffer += chunk;
	} while (status);
	return buffer;
}
