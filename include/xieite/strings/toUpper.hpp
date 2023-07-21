#ifndef XIEITE_HEADER_STRINGS_TOUPPER
#	define XIEITE_HEADER_STRINGS_TOUPPER

#	include <string>

namespace xieite::strings {
	constexpr char toUpper(char character) noexcept {
		if ((character >= 'a') && (character <= 'z')) {
			character -= ('a' - 'A');
		}
		return character;
	}

	constexpr std::string toUpper(std::string string) noexcept {
		for (char& character : string) {
			character = xieite::strings::toUpper(character);
		}
		return string;
	}
}

#endif
