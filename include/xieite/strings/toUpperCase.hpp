#ifndef XIEITE_HEADER_STRINGS_TOUPPERCASE
#	define XIEITE_HEADER_STRINGS_TOUPPERCASE

#	include <string>

namespace xieite::strings {
	constexpr char toUpperCase(char character) noexcept {
		if ((character >= 'a') && (character <= 'z')) {
			character -= ('a' - 'A');
		}
		return character;
	}

	constexpr std::string toUpperCase(std::string string) noexcept {
		const std::size_t stringSize = string.size();
		for (std::size_t i = 0; i < stringSize; ++i) {
			string[i] = xieite::strings::toUpperCase(string[i]);
		}
		return string;
	}
}

#endif
