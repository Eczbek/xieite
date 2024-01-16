#ifndef XIEITE_HEADER_STRINGS_PAD_FRONT
#	define XIEITE_HEADER_STRINGS_PAD_FRONT

#	include <concepts>
#	include <cstddef>
#	include <string>

namespace xieite::strings {
	[[nodiscard]] constexpr std::string padFront(const std::string& value, const std::size_t size, const char padding = ' ') noexcept {
		if (value.size() < size) {
			return std::string(size - value.size(), padding) + value;
		}
		return value;
	}
}

#endif
