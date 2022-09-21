
#include <cstdio>
#include <gcufl/console/cursor/getPosition.hpp>
#include <gcufl/console/cursor/Position.hpp>
#include <gcufl/console/locks/Raw.hpp>
#include <iostream>
#include <string>


gcufl::console::cursor::Position gcufl::console::cursor::getPosition() noexcept {
	gcufl::console::locks::Raw rawLock;
	std::cout << "\u001b[6n";
	gcufl::console::cursor::Position position;
	std::scanf("\u001b[%d;%dR", &position.row, &position.column);
	return gcufl::console::cursor::Position(position.row - 1, position.column - 1);
}
