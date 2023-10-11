#ifndef XIEITE_HEADER_STRINGS_IS_DIGIT
#	define XIEITE_HEADER_STRINGS_IS_DIGIT

#	include <string_view>

namespace xieite::strings {
	[[nodiscard]] constexpr bool isDigit(const char character) noexcept {
		return std::string_view("0123456789").contains(character);
	}
}

#endif
