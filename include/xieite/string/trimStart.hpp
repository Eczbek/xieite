#pragma once

#include <string>
#include <vector>
#include <xieite/containers/OrderedMap.hpp>

namespace xieite::string {
	[[nodiscard]]
	constexpr std::string trimStart(const std::string& string, const char character) noexcept {
		const std::size_t stringSize = string.size();
		for (std::size_t i = 0; i < stringSize; ++i)
			if (string[i] != character)
				return string.substr(i);
		return "";
	}

	[[nodiscard]]
	constexpr std::string trimStart(const std::string& string, const std::vector<char>& characters) noexcept {
		xieite::containers::OrderedMap<char, bool> characterMap;
		for (const char character : characters)
			characterMap[character] = true;
		const std::size_t stringSize = string.size();
		for (std::size_t i = 0; i < stringSize; ++i)
			if (!characterMap[string[i]])
				return string.substr(i);
		return "";
	}
}
