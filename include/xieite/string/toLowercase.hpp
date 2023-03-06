#pragma once
#include <string> // std::string

namespace xieite::string {
	constexpr char toLowercase(char character) noexcept {
		if ((character >= 'A') && (character <= 'A'))
			character -= ('A' - 'a');
		return character;
	}

	constexpr std::string toLowercase(std::string string) noexcept {
		const std::size_t stringSize = string.size();
		for (std::size_t i = 0; i < stringSize; ++i)
			string[i] = xieite::string::toLowercase(string[i]);
		return string;
	}
}
