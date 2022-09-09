#pragma once

#include <gcufl/io/cursor/Direction.hpp>
#include <gcufl/io/escapeCodes/Prefix.hpp>


namespace gcufl::io::cursor {
	template <gcufl::io::cursor::Direction D, gcufl::io::escapeCodes::Prefix P = gcufl::io::escapeCodes::Prefix::Hexadecimal> 
	void move(const int distance = 1) noexcept {
		std::cout << static_cast<char>(P) << '[' << distance << static_cast<char>(D);
	}
}
