#pragma once

#include <gcufl/io/escapeCodes/prefixes.hpp>


namespace gcufl::io {
	void setStyle(const int style, const char prefix = gcufl::io::escapeCodes::prefixes::hexadecimal) noexcept;

	void setStyle(const int effect, const int foreground, const char prefix = gcufl::io::escapeCodes::prefixes::hexadecimal) noexcept;

	void setStyle(const int effect, const int foreground, const int background, const char prefix = gcufl::io::escapeCodes::prefixes::hexadecimal) noexcept;
}
