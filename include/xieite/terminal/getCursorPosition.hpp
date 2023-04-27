#pragma once

#include <cstdio>
#include <iostream>
#include <xieite/terminal/Position.hpp>
#include <xieite/terminal/ModeLock.hpp>

namespace xieite::terminal {
	[[nodiscard]]
	inline xieite::terminal::Position getCursorPosition() {
		xieite::terminal::ModeLock modeLock;
		std::cout << "\u001b[6n";
		xieite::terminal::Position position;
		std::scanf("\u001b[%i;%iR", &position.row, &position.column);
		return xieite::terminal::Position(position.row - 1, position.column - 1);
	}
}
