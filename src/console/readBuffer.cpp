#include <cstddef> // std::size_t
#include <string> // std::string
#include <unistd.h> // STDIN_FILENO, read
#include <xieite/console/NonBlockLock.hpp>
#include <xieite/console/RawLock.hpp>
#include <xieite/console/readBuffer.hpp>

std::string xieite::console::readBuffer(const std::size_t chunkSize) noexcept {
	xieite::console::RawLock RawLock;
	xieite::console::NonBlockLock NonBlockLock;
	std::string buffer;
	int status;
	do {
		std::string chunk(chunkSize, '\0');
		status = read(STDIN_FILENO, chunk.data(), chunkSize);
		buffer += chunk;
	} while (status > 0);
	return buffer;
}
