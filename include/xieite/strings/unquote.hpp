#ifndef XIEITE_HEADER_STRINGS_UNQUOTE
#	define XIEITE_HEADER_STRINGS_UNQUOTE

#	include <string>
#	include <string_view>
#	include "../strings/replace.hpp"

namespace xieite::strings {
	[[nodiscard]] constexpr std::string unquote(std::string_view value, const char delimiter = '"', const char escape = '\\') noexcept {
		value.remove_prefix(value[0] == delimiter);
		value.remove_suffix(value[value.size() - 1] == delimiter);
		return xieite::strings::replace((delimiter == escape) ? value : xieite::strings::replace(value, std::string(2, escape), escape), std::string(1, escape) + delimiter, delimiter);
	}
}

#endif
