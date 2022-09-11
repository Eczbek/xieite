#pragma once

#include <gcufl/io/escapeCodes/prefixes.hpp>


namespace gcufl::io {
	void eraseLine(const int erasor, const char prefix = gcufl::io::escapeCodes::prefixes::hexadecimal) noexcept;
}
