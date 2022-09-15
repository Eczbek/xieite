#pragma once

#include <gcufl/io/escapeCodes/prefixes.hpp>


namespace gcufl::io::cursor {
	void move(const char direction, const int distance = 1, const char prefix = gcufl::io::escapeCodes::prefixes::hexadecimal) noexcept;
}
