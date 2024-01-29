#ifndef XIEITE_HEADER_STRINGS_QUOTE
#	define XIEITE_HEADER_STRINGS_QUOTE

#	include <string>
#	include <string_view>
#	include "../strings/replace.hpp"

namespace xieite::strings {
	[[nodiscard]] constexpr std::string quote(const std::string_view value, const char delimiter = '"', const char escape = '\\') noexcept {
		return delimiter + xieite::strings::replace((delimiter == escape) ? value : xieite::strings::replace(value, escape, std::string(2, escape)), delimiter, std::string(1, escape) + delimiter) + delimiter;
	}
}

#endif
