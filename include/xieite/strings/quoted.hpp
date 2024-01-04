#ifndef XIEITE_HEADER_STRINGS_QUOTED
#	define XIEITE_HEADER_STRINGS_QUOTED

#	include <string>
#	include <string_view>
#	include "../strings/replace.hpp"

namespace xieite::strings {
	[[nodiscard]] constexpr std::string quoted(const std::string_view value, const char delimiter = '"', const char escape = '\\') noexcept {
		return delimiter + xieite::strings::replace((delimiter == escape) ? value : xieite::strings::replace(value, escape, std::string(2, escape)), delimiter, std::string(1, escape) + delimiter) + delimiter;
	}
}

#endif
