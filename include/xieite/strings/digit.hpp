#ifndef XIEITE_HEADER_STRINGS_DIGIT
#	define XIEITE_HEADER_STRINGS_DIGIT

#	include <string_view>

namespace xieite::strings {
	[[nodiscard]] constexpr bool digit(const char character) noexcept {
		return (character >= '0') && (character <= '9');
		// Apparently digits are guaranteed to be in order
	}
}

#endif
