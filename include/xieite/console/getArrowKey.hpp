#pragma once

#include <xieite/console/getCharacter.hpp>

namespace xieite::console {
	inline char getArrowKey(const bool echo = false) noexcept {
		return ((xieite::console::getCharacter(echo) == '\x1b') && (xieite::console::getCharacter(echo) == '[')) ? xieite::console::getCharacter(echo) : 0;
	}
}
