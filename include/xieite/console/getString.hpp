#pragma once

#include <iostream>
#include <string>
#include <xieite/console/ModeLock.hpp>

namespace xieite::console {
	inline std::string getString() noexcept {
		xieite::console::ModeLock modeLock;
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
