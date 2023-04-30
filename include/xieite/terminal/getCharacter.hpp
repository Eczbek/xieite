#pragma once

#include <unistd.h>
#include <xieite/terminal/ModeLock.hpp>

namespace xieite::terminal {
	inline char getCharacter(const xieite::terminal::ModeLock& modeLock) {
		char input;
		return (read(STDIN_FILENO, &input, 1) > 0) ? input : 0;
	}

	inline char getCharacter() {
		return xieite::terminal::getCharacter(xieite::terminal::ModeLock());
	}
}
