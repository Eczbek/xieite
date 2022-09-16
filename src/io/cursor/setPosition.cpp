
#include <gcufl/io/cursor/setPosition.hpp>
#include <gcufl/io/cursor/Position.hpp>
#include <iostream>

void gcufl::io::cursor::setPosition(const gcufl::io::cursor::Position position) noexcept {
	std::cout << "\u001b[" << (position.row + 1) << ';' << (position.column + 1) << 'H';
}
