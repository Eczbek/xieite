#pragma once
#include <string> // std::string
#include <unistd.h> // STDIN_FILENO, read
#include <xieite/console/NonBlockLock.hpp>
#include <xieite/console/RawLock.hpp>

namespace xieite::console {
	inline std::string readBuffer() noexcept {
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
}
