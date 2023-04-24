#pragma once

#include <iostream>
#include <xieite/console/ModeLock.hpp>

namespace xieite::console {
	inline char getCharacter(const bool echo = false) {
		xieite::console::ModeLock modeLock;
		modeLock.setEcho(echo);
		return std::cin.get();
	}
}
