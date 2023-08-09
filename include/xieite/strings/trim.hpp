#ifndef XIEITE_HEADER__STRINGS__TRIM
#	define XIEITE_HEADER__STRINGS__TRIM

#	include <string>
#	include "../concepts/RangeOf.hpp"
#	include "../strings/trimBack.hpp"
#	include "../strings/trimFront.hpp"

namespace xieite::strings {
	constexpr std::string trim(const std::string& string, const char character) noexcept {
		return xieite::strings::trimBack(xieite::strings::trimFront(string, character), character);
	}

	template<xieite::concepts::RangeOf<char> CharacterRange>
	constexpr std::string trim(const std::string& string, const CharacterRange& characters) noexcept {
		return xieite::strings::trimBack(xieite::strings::trimFront(string, characters), characters);
	}
}

#endif
