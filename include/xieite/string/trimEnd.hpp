#pragma once
#include <string> // std::string
#include <vector> // std::vector
#include <xieite/containers/OrderedMap.hpp> // xieite::containers::OrderedMap

namespace xieite::string {
	[[nodiscard]]
	constexpr std::string trimEnd(const std::string& string, const char character) noexcept {
		for (std::size_t i = string.size(); i--;)
			if (string[i] != character)
				return string.substr(0, i);
		return "";
	}

	[[nodiscard]]
	constexpr std::string trimEnd(const std::string& string, const std::vector<char>& characters) noexcept {
		xieite::containers::OrderedMap<char, bool> characterMap;
		for (const char character : characters)
			characterMap[character] = true;
		for (std::size_t i = string.size(); i--;)
			if (!characterMap[string[i]])
				return string.substr(0, i);
		return "";
	}
}
