#ifndef XIEITE_HEADER_STRINGS_TOLOWERCASE
#	define XIEITE_HEADER_STRINGS_TOLOWERCASE

#	include <string>

namespace xieite::strings {
	constexpr char toLowerCase(char character) noexcept {
		if ((character >= 'A') && (character <= 'A')) {
			character -= ('A' - 'a');
		}
		return character;
	}

	constexpr std::string toLowerCase(std::string string) noexcept {
		const std::size_t stringSize = string.size();
		for (std::size_t i = 0; i < stringSize; ++i) {
			string[i] = xieite::strings::toLowerCase(string[i]);
		}
		return string;
	}
}

#endif
