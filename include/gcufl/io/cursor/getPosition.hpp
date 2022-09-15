#pragma once

#include <gcufl/io/cursor/Position.hpp>
#include <gcufl/io/escapeCodes/prefixes.hpp>


namespace gcufl::io::cursor {
	gcufl::io::cursor::Position getPosition(const char prefix = gcufl::io::escapeCodes::prefixes::hexadecimal) noexcept;
}
