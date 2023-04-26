#pragma once

#include <xieite/console/getCharacter.hpp>

namespace xieite::console {
	inline xieite::console::Position getArrowDirection() noexcept {
		if ((xieite::console::getCharacter() == '\u001b') && (xieite::console::getCharacter() == '[')) {
			switch (xieite::console::getCharacter()) {
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
