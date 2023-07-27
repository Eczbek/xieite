#ifndef XIEITE_HEADER_STRINGS_TOLOWER
#	define XIEITE_HEADER_STRINGS_TOLOWER

#	include <string>

namespace xieite::strings {
	constexpr char toLower(const char character) noexcept {
		return (character + ('a' - 'A') * ((character >= 'A') && (character <= 'Z')));
	}

	constexpr std::string toLower(std::string string) noexcept {
		for (char& character : string) {
			character = xieite::strings::toLower(character);
		}
		return string;
	}
}

#endif
