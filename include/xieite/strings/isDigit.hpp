#ifndef XIEITE_HEADER__STRINGS__IS_DIGIT
#	define XIEITE_HEADER__STRINGS__IS_DIGIT

#	include <string_view>

namespace xieite::strings {
	constexpr bool isDigit(const char character) noexcept {
		return std::string_view("0123456789").contains(character);
	}
}

#endif
