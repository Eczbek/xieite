#ifndef XIEITE_HEADER_STRINGS_TRIM
#	define XIEITE_HEADER_STRINGS_TRIM

#	include <string>
#	include <xieite/concepts/RangeOf.hpp>
#	include <xieite/strings/trimBack.hpp>
#	include <xieite/strings/trimFront.hpp>

namespace xieite::strings {
	[[nodiscard]]
	constexpr std::string trim(const std::string& string, const char character) noexcept {
		return xieite::strings::trimBack(xieite::strings::trimFront(string, character), character);
	}

	template<xieite::concepts::RangeOf<char> CharacterRange>
	[[nodiscard]]
	constexpr std::string trim(const std::string& string, const CharacterRange& characters) noexcept {
		return xieite::strings::trimBack(xieite::strings::trimFront(string, characters), characters);
	}
}

#endif
