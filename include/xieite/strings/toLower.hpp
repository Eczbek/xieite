#ifndef XIEITE_HEADER_STRINGS_TOLOWERCASE
#	define XIEITE_HEADER_STRINGS_TOLOWERCASE

#	include <string>

namespace xieite::strings {
	constexpr char toLower(char character) noexcept {
		if ((character >= 'A') && (character <= 'Z')) {
			character += ('a' - 'A');
		}
		return character;
	}

	constexpr std::string toLower(std::string string) noexcept {
		const std::size_t stringSize = string.size();
		for (std::size_t i = 0; i < stringSize; ++i) {
			string[i] = xieite::strings::toLower(string[i]);
		}
		return string;
	}
}

#endif
