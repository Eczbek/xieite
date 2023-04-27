#pragma once

#include <iostream>
#include <string>
#include <xieite/terminal/ModeLock.hpp>

namespace xieite::terminal {
	inline std::string getString() noexcept {
		xieite::terminal::ModeLock modeLock;
		modeLock.setBlocking(false);
		std::string buffer;
		while (true) {
			const char input = std::cin.get();
			if (!input) {
				break;
			}
			buffer += input;
		}
		return buffer;
	}
}
