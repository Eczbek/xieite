#ifndef XIEITE_HEADER_STRINGS_PAD_FRONT
#	define XIEITE_HEADER_STRINGS_PAD_FRONT

#	include <concepts>
#	include <cstddef>
#	include <string>
#	include "../concepts/string.hpp"

namespace xieite::strings {
	template<xieite::concepts::String String = std::string>
	[[nodiscard]] constexpr String padFront(const String& value, const std::size_t size, const String::value_type padding = ' ') noexcept {
		if (value.size() < size) {
			return String(size - value.size(), padding) + value;
		}
		return value;
	}
}

#endif
