#ifndef XIEITE_HEADER_STRINGS_TOUPPER
#	define XIEITE_HEADER_STRINGS_TOUPPER

#	include <string>

namespace xieite::strings {
	constexpr char toUpper(const char character) noexcept {
		return (character - ('a' - 'A') * ((character >= 'a') && (character <= 'z')));
	}

	constexpr std::string toUpper(std::string string) noexcept {
		for (char& character : string) {
			character = xieite::strings::toUpper(character);
		}
		return string;
	}
}

#endif
