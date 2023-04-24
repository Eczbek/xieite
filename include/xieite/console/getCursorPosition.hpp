#pragma once

#include <cstdio>
#include <iostream>
#include <xieite/console/Position.hpp>
#include <xieite/console/ModeLock.hpp>

namespace xieite::console {
	[[nodiscard]]
	inline xieite::console::Position getCursorPosition() {
		xieite::console::ModeLock modeLock;
		std::cout << "\u001b[6n";
		xieite::console::Position position;
		std::scanf("\u001b[%i;%iR", &position.row, &position.column);
		return xieite::console::Position(position.row - 1, position.column - 1);
	}
}
