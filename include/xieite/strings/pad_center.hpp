#ifndef XIEITE_HEADER_STRINGS_PAD_CENTER
#	define XIEITE_HEADER_STRINGS_PAD_CENTER

#	include <concepts>
#	include <cstddef>
#	include <string>

namespace xieite::strings {
	[[nodiscard]] constexpr std::string padCenter(const std::string& value, const std::size_t size, const char padding = ' ', const bool alignFront = true) noexcept {
		if (value.size() < size) {
			return std::string((size - value.size() + !alignFront) / 2, padding) + value + std::string((size - value.size() + alignFront) / 2, padding);
		}
		return value;
	}
}

#endif
