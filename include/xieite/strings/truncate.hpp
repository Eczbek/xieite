#ifndef XIEITE_HEADER_STRINGS_TRUNCATE
#	define XIEITE_HEADER_STRINGS_TRUNCATE

#	include <cstddef>
#	include <string>
#	include "../concepts/string.hpp"

namespace xieite::strings {
	template<xieite::concepts::String String = std::string>
	[[nodiscard]] constexpr String truncate(const String& string, const std::size_t length, const String& suffix = "") noexcept {
		return (string.size() <= length) ? string : ((suffix.size() > length) ? suffix.substr(0, length) : (string.substr(0, length - suffix.size()) + suffix));
	}
}

#endif
