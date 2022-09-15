#pragma once

#include <gcufl/io/cursor/Position.hpp>
#include <gcufl/io/escapeCodes/prefixes.hpp>


namespace gcufl::io::cursor {
	void setPosition(const gcufl::io::cursor::Position position, const char prefix = gcufl::io::escapeCodes::prefixes::hexadecimal) noexcept;
}
