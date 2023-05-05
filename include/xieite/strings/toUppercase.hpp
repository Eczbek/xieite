#pragma once

#include <string>

namespace xieite::strings {
	constexpr char toUppercase(char character) noexcept {
		if ((character >= 'a') && (character <= 'z')) {
			character += ('A' - 'a');
		}
		return character;
	}

	constexpr std::string toUppercase(std::string string) noexcept {
		const std::size_t stringSize = string.size();
		for (std::size_t i = 0; i < stringSize; ++i) {
			string[i] = xieite::strings::toUppercase(string[i]);
		}
		return string;
	}
}
