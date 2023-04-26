#pragma once

#include <iostream>
#include <xieite/console/ModeLock.hpp>

namespace xieite::console {
	inline char getCharacter(const bool blocking = true) {
		const xieite::console::ModeLock modeLock;
		modeLock.setBlocking(blocking);
		return std::cin.get();
	}
}
