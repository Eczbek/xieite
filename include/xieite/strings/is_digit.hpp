#ifndef XIEITE_HEADER_STRINGS_IS_DIGIT
#	define XIEITE_HEADER_STRINGS_IS_DIGIT

#	include <string_view>
#	include "../concepts/character.hpp"

namespace xieite::strings {
	template<xieite::concepts::Character Character = char>
	[[nodiscard]] constexpr bool isDigit(const Character character) noexcept {
		return (character >= '0') && (character <= '9');
		// https://eel.is/c++draft/lex.charset#9.sentence-5
	}
}

#endif
