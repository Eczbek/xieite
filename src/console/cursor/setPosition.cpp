
#include <gcufl/console/cursor/setPosition.hpp>
#include <gcufl/console/cursor/Position.hpp>
#include <iostream>

void gcufl::console::cursor::setPosition(const gcufl::console::cursor::Position position) noexcept {
	std::cout << "\x1b[" << (position.row + 1) << ';' << (position.column + 1) << 'H';
}
