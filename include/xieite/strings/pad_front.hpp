#ifndef XIEITE_HEADER_STRINGS_PAD_FRONT
#	define XIEITE_HEADER_STRINGS_PAD_FRONT

#	include <cstddef>
#	include <string>
#	include <string_view>

namespace xieite::strings {
	[[nodiscard]] constexpr std::string padFront(const std::string_view value, const std::size_t size, const char padding = ' ') noexcept {
		std::string result = std::string(value);
		result.reserve(size);
		const std::size_t valueSize = value.size();
		if (valueSize < size) {
			result = std::string(size - valueSize, padding) + result;
		}
		return result;
	}
}

#endif
