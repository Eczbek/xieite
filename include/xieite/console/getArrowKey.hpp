#pragma once

#include <xieite/console/getCharacter.hpp>

namespace xieite::console {
	inline xieite::console::Position getArrowKey(const bool echo = false) noexcept {
		if ((xieite::console::getCharacter(echo) == '\u001b') && (xieite::console::getCharacter(echo) == '[')) {
			switch (xieite::console::getCharacter(echo)) {
				case 'A':
					return xieite::console::Position(0, -1);
				case 'B':
					return xieite::console::Position(0, 1);
				case 'C':
					return xieite::console::Position(1, 0);
				case 'D':
					return xieite::console::Position(-1, 0);
			}
		}
		return xieite::console::Position(0, 0);
	}
}
