
#include <xieite/console/cursor/setPosition.hpp>
#include <xieite/console/cursor/Position.hpp>
#include <iostream>

void xieite::console::cursor::setPosition(const xieite::console::cursor::Position position) noexcept {
	std::cout << "\x1b[" << (position.row + 1) << ';' << (position.column + 1) << 'H';
}
