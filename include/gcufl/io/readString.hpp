#pragma once

#include <ios>
#include <limits>
#include <string>


namespace gcufl::io {
	std::string readString(const std::streamsize count = std::numeric_limits<std::streamsize>::max(), const char until = std::char_traits<char>::eof()) noexcept;
}
