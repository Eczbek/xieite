#pragma once

#include <gcufl/io/escapeCodes/prefixes.hpp>


namespace gcufl::io {
	void eraseScreen(const int erasor, const char prefix = gcufl::io::escapeCodes::prefixes::hexadecimal) noexcept;
}
