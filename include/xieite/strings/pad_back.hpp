#ifndef XIEITE_HEADER_STRINGS_PAD_BACK
#	define XIEITE_HEADER_STRINGS_PAD_BACK

#	include <concepts>
#	include <cstddef>
#	include <string>

namespace xieite::strings {
	[[nodiscard]] constexpr std::string padBack(const std::string& value, const std::size_t size, const char padding = ' ') noexcept {
		if (value.size() < size) {
			return value + std::string(size - value.size(), padding);
		}
		return value;
	}
}

#endif
