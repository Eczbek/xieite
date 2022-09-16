
#include <cstdio>
#include <gcufl/io/cursor/getPosition.hpp>
#include <gcufl/io/cursor/Position.hpp>
#include <gcufl/io/locks/Raw.hpp>
#include <iostream>
#include <string>


gcufl::io::cursor::Position gcufl::io::cursor::getPosition() noexcept {
	gcufl::io::locks::Raw rawLock;
	std::cout << "\u001b[6n";
	gcufl::io::cursor::Position position;
	std::scanf("\u001b[%d;%dR", &position.row, &position.column);
	return gcufl::io::cursor::Position(position.row - 1, position.column - 1);
}
