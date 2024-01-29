#ifndef XIEITE_HEADER_STRINGS_IS_DIGIT
#	define XIEITE_HEADER_STRINGS_IS_DIGIT

#	include <string_view>

namespace xieite::strings {
	[[nodiscard]] constexpr bool isDigit(const char character) noexcept {
		return (character >= '0') && (character <= '9'); // Apparently digits are guaranteed to be in order
	}
}

#endif
