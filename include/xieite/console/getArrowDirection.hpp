#pragma once

#include <xieite/console/ModeLock.hpp>
#include <xieite/console/getCharacter.hpp>

namespace xieite::console {
	inline xieite::console::Position getArrowDirection(const xieite::console::ModeLock& modeLock) {
		const char character = xieite::console::getCharacter(modeLock);
		if (character == '\u001b') {
			if (xieite::console::getCharacter(modeLock) == '[') {
				const char direction = xieite::console::getCharacter(modeLock);
				switch (character) {
					case 'A':
						return xieite::console::Position(-1, 0);
					case 'B':
						return xieite::console::Position(1, 0);
					case 'C':
						return xieite::console::Position(0, 1);
					case 'D':
						return xieite::console::Position(0, -1);
				}
				std::cin.putback(direction);
			}
			std::cin.putback('[');
		}
		std::cin.putback(character);
		return xieite::console::Position(0, 0);
	}

	inline xieite::console::Position getArrowDirection() {
		return xieite::console::Position(xieite::console::ModeLock());
	}
}
