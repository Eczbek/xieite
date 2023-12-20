#ifndef XIEITE_HEADER_STRINGS_HASH_DJB2
#	define XIEITE_HEADER_STRINGS_HASH_DJB2

#	include <cstddef>
#	include <string_view>

namespace xieite::strings {
	[[nodiscard]] constexpr std::size_t hashDjb2(const std::string_view value) noexcept {
		std::size_t result = 5381;
		for (const char character : value) {
			result = result * 33 + character;
		}
		return result;
	}
}

#endif
