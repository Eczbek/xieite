#pragma once

#include <iostream>
#include <variant>
#include <xieite/console/Position.hpp>
#include <xieite/console/getArrowDirection.hpp>
#include <xieite/console/getCharacter.hpp>

namespace xieite::console {
	inline std::variant<char, xieite::console::Position> getCharacterOrArrowDirection(const bool blocking = true) noexcept {
		const char character = xieite::console::getCharacter(blocking);
		if (character == '\u001b') {
			if (xieite::console::getCharacter(blocking) == '[') {
				const char direction = xieite::console::getCharacter(blocking);
				switch (direction) {
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
		return character;
	}
}
