#pragma once

#include <iostream>
#include <xieite/terminal/ModeLock.hpp>

namespace xieite::terminal {
	inline char getCharacter(const xieite::terminal::ModeLock& modeLock) {
		return std::cin.get();
	}

	inline char getCharacter() {
		return xieite::terminal::getCharacter(xieite::terminal::ModeLock());
	}
}
