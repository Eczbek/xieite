#ifndef XIEITE_HEADER_STRINGS_PAD_BACK
#	define XIEITE_HEADER_STRINGS_PAD_BACK

#	include <concepts>
#	include <cstddef>
#	include <string>
#	include "../concepts/string.hpp"

namespace xieite::strings {
	template<xieite::concepts::String String = std::string>
	[[nodiscard]] constexpr String padBack(const String& value, const std::size_t size, const String::value_type padding = ' ') noexcept {
		if (value.size() < size) {
			return value + String(size - value.size(), padding);
		}
		return value;
	}
}

#endif
