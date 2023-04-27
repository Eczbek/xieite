#pragma once

#include <xieite/terminal/ModeLock.hpp>
#include <xieite/terminal/getCharacter.hpp>

namespace xieite::terminal {
	inline xieite::terminal::Position getArrowDirection(const xieite::terminal::ModeLock& modeLock) {
		const char character = xieite::terminal::getCharacter(modeLock);
		if (character == '\u001b') {
			if (xieite::terminal::getCharacter(modeLock) == '[') {
				const char direction = xieite::terminal::getCharacter(modeLock);
				switch (character) {
					case 'A':
						return xieite::terminal::Position(-1, 0);
					case 'B':
						return xieite::terminal::Position(1, 0);
					case 'C':
						return xieite::terminal::Position(0, 1);
					case 'D':
						return xieite::terminal::Position(0, -1);
				}
				std::cin.putback(direction);
			}
			std::cin.putback('[');
		}
		std::cin.putback(character);
		return xieite::terminal::Position(0, 0);
	}

	inline xieite::terminal::Position getArrowDirection() {
		return xieite::terminal::Position(xieite::terminal::ModeLock());
	}
}
