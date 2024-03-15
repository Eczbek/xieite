#ifndef XIEITE_HEADER_STRINGS_QUOTE
#	define XIEITE_HEADER_STRINGS_QUOTE

#	include <string>
#	include <string_view>
#	include "../strings/replace.hpp"

namespace xieite::strings {
	[[nodiscard]] constexpr std::string quote(const std::string_view value, const char delimiter = '"', const char escape = '\\') noexcept {
		std::string result = std::string(1, delimiter);
		const std::string escapeDelimiter = std::string(1, escape) + delimiter;
		if (delimiter == escape) {
			result += xieite::strings::replace(value, delimiter, escapeDelimiter);
		} else {
			const std::string escapeEscape = std::string(2, escape);
			const std::string temporary = xieite::strings::replace(value, escape, escapeEscape);
			result += xieite::strings::replace(temporary, delimiter, escapeDelimiter);
		}
		return result + delimiter;
	}
}

#endif
