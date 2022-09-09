#pragma once

#include <gcufl/io/cursor/Position.hpp>
#include <gcufl/io/escapeCodes/Prefix.hpp>


namespace gcufl::io::cursor {
	template <gcufl::io::escapeCodes::Prefix P = gcufl::io::escapeCodes::Prefix::Hexadecimal> 
	void setPosition(const gcufl::io::cursor::Position position) noexcept {
		std::cout << static_cast<char>(P) << '[' << (position.row + 1) << ';' << (position.column + 1) << 'H';
	}
}
