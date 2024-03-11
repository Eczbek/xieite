#ifndef XIEITE_HEADER_STRINGS_QUOTE
#	define XIEITE_HEADER_STRINGS_QUOTE

#	include <string>
#	include "../concepts/string.hpp"
#	include "../strings/replace.hpp"
#	include "../strings/view.hpp"

namespace xieite::strings {
	template<xieite::concepts::String String = std::string>
	[[nodiscard]] constexpr String quote(const xieite::strings::View<String> value, const typename String::value_type delimiter = '"', const typename String::value_type escape = '\\') noexcept {
		return delimiter + xieite::strings::replace((delimiter == escape) ? value : xieite::strings::replace(value, escape, String(2, escape)), delimiter, String(1, escape) + delimiter) + delimiter;
	}
}

#endif
