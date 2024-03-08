#ifndef XIEITE_HEADER_STRINGS_UNQUOTE
#	define XIEITE_HEADER_STRINGS_UNQUOTE

#	include <string>
#	include <string_view>
#	include "../concepts/string.hpp"
#	include "../strings/replace.hpp"
#	include "../strings/view.hpp"

namespace xieite::strings {
	template<xieite::concepts::String String = std::string>
	[[nodiscard]] constexpr String unquote(xieite::strings::View<String> value, const String::value_type delimiter = '"', const String::value_type escape = '\\') noexcept {
		value.remove_prefix(value[0] == delimiter);
		value.remove_suffix(value[value.size() - 1] == delimiter);
		return xieite::strings::replace((delimiter == escape) ? value : xieite::strings::replace(value, String(2, escape), escape), String(1, escape) + delimiter, delimiter);
	}
}

#endif
