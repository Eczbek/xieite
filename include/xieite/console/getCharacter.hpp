#pragma once

#include <iostream>
#include <xieite/console/ModeLock.hpp>

namespace xieite::console {
	inline char getCharacter(const xieite::console::ModeLock& modeLock) {
		return std::cin.get();
	}

	inline char getCharacter() {
		return xieite::console::getCharacter(xieite::console::ModeLock());
	}
}
