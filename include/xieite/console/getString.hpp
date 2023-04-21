#pragma once

#include <string>
#include <unistd.h>
#include <xieite/console/ModeLock.hpp>

namespace xieite::console {
	inline std::string getString() noexcept {
		xieite::console::ModeLock modeLock;
		modeLock.setBlocking(false);
		std::string buffer;
		while (true) {
			char input = 0;
			read(STDIN_FILENO, &input, 1);
			if (!input) {
				break;
			}
			buffer += input;
		}
		return buffer;
	}
}
