#include <cstdio>
#include <iostream>
#include <string>
#include <xieite/console/cursor/getPosition.hpp>
#include <xieite/console/cursor/Position.hpp>
#include <xieite/console/locks/Raw.hpp>

xieite::console::cursor::Position xieite::console::cursor::getPosition() noexcept {
	xieite::console::locks::Raw rawLock;
	std::cout << "\x1b[6n";
	xieite::console::cursor::Position position;
	std::scanf("\x1b[%d;%dR", &position.row, &position.column);
	return xieite::console::cursor::Position(position.row - 1, position.column - 1);
}
