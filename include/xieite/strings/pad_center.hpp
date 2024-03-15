#ifndef XIEITE_HEADER_STRINGS_PAD_CENTER
#	define XIEITE_HEADER_STRINGS_PAD_CENTER

#	include <cstddef>
#	include <string>
#	include <string_view>

namespace xieite::strings {
	[[nodiscard]] constexpr std::string padCenter(const std::string_view value, const std::size_t size, const char padding = ' ', const bool alignFront = true) noexcept {
		std::string result = std::string(value);
		result.reserve(size);
		const std::size_t valueSize = value.size();
		if (valueSize < size) {
			result = std::string((size - valueSize + !alignFront) / 2, padding) + result + std::string((size - valueSize + alignFront) / 2, padding);
		}
		return result;
	}
}

#endif
