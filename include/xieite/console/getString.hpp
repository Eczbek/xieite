#pragma once
#include <string> // std::string
#include <unistd.h> // STDIN_FILENO, read
#include <xieite/console/NonBlockLock.hpp>
#include <xieite/console/RawLock.hpp>

namespace xieite::console {
	inline std::string getString() noexcept {
		xieite::console::RawLock rawLock;
		xieite::console::NonBlockLock nonBlockLock;
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
