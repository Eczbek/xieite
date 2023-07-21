#ifndef XIEITE_HEADER_STRINGS_TOLOWER
#	define XIEITE_HEADER_STRINGS_TOLOWER

#	include <string>

namespace xieite::strings {
	constexpr char toLower(char character) noexcept {
		if ((character >= 'A') && (character <= 'Z')) {
			character += ('a' - 'A');
		}
		return character;
	}

	constexpr std::string toLower(std::string string) noexcept {
		for (char& character : string) {
			character = xieite::strings::toLower(character);
		}
		return string;
	}
}

#endif
