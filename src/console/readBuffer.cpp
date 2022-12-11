#include <string> // std::string
#include <unistd.h> // STDIN_FILENO, read
#include <xieite/console/NonBlockLock.hpp>
#include <xieite/console/RawLock.hpp>
#include <xieite/console/readBuffer.hpp>

std::string xieite::console::readBuffer() noexcept {
	xieite::console::RawLock RawLock;
	xieite::console::NonBlockLock NonBlockLock;
	std::string buffer;
	while (true) {
		char input = 0;
		read(STDIN_FILENO, &input, 1);
		if (!input)
			break;
		buffer += input;
	}
	return buffer;
}
