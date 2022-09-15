
#include <cstdio>
#include <gcufl/io/cursor/getPosition.hpp>
#include <gcufl/io/cursor/Position.hpp>
#include <gcufl/io/locks/Raw.hpp>
#include <iostream>
#include <string>


gcufl::io::cursor::Position gcufl::io::cursor::getPosition(const char prefix) noexcept {
	gcufl::io::locks::Raw rawLock;
	std::cout << prefix << "[6n";
	gcufl::io::cursor::Position position;
	std::scanf((std::string(1, prefix) + "[%d;%dR").c_str(), &position.row, &position.column);
	return gcufl::io::cursor::Position(position.row - 1, position.column - 1);
}
