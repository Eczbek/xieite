#pragma once

#include <iostream>
#include <variant>
#include <xieite/console/Position.hpp>
#include <xieite/console/getArrowKey.hpp>
#include <xieite/console/getCharacter.hpp>

namespace xieite::console {
	inline std::variant<char, xieite::console::Position> getArrowKeyOrCharacter(const bool echo = false) noexcept {
		const char character = xieite::console::getCharacter(echo);
		if (character == '\u001b') {
			std::cin.putback(character);
			return xieite::console::getArrowKey(echo);
		}
		return character;
	}
}
