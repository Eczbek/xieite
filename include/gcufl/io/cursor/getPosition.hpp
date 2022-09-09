#pragma once

#include <cstdio>
#include <gcufl/io/cursor/Position.hpp>
#include <gcufl/io/escapeCodes/Prefix.hpp>
#include <gcufl/io/locks/Raw.hpp>
#include <iostream>
#include <string>


namespace gcufl::io::cursor {
	template <gcufl::io::escapeCodes::Prefix P = gcufl::io::escapeCodes::Prefix::Hexadecimal> 
	gcufl::io::cursor::Position getPosition() noexcept {
		gcufl::io::locks::Raw rawLock;
		std::cout << static_cast<char>(P) << "[6n";
		gcufl::io::cursor::Position position;
		std::scanf((std::string(1, static_cast<char>(P)) + "[%d;%dR").c_str(), &position.row, &position.column);
		return gcufl::io::cursor::Position(position.row - 1, position.column - 1);
	}
}
