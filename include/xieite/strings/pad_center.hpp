#ifndef XIEITE_HEADER_STRINGS_PAD_CENTER
#	define XIEITE_HEADER_STRINGS_PAD_CENTER

#	include <concepts>
#	include <cstddef>
#	include <string>
#	include "../concepts/string.hpp"

namespace xieite::strings {
	template<xieite::concepts::String String = std::string>
	[[nodiscard]] constexpr String padCenter(const String& value, const std::size_t size, const typename String::value_type padding = ' ', const bool alignFront = true) noexcept {
		if (value.size() < size) {
			return String((size - value.size() + !alignFront) / 2, padding) + value + std::string((size - value.size() + alignFront) / 2, padding);
		}
		return value;
	}
}

#endif
