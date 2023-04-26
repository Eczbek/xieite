#pragma once

#include <xieite/console/getCharacter.hpp>

namespace xieite::console {
	inline xieite::console::Position getArrowDirection(const bool blocking = true) noexcept {
		if ((xieite::console::getCharacter(blocking) == '\u001b') && (xieite::console::getCharacter(blocking) == '[')) {
			switch (xieite::console::getCharacter(blocking)) {
				case 'A':
					return xieite::console::Position(-1, 0);
				case 'B':
					return xieite::console::Position(1, 0);
				case 'C':
					return xieite::console::Position(0, 1);
				case 'D':
					return xieite::console::Position(0, -1);
			}
		}
		return xieite::console::Position(0, 0);
	}
}
