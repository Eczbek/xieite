
#include <cstddef>
#include <gcufl/string/trimEnd.hpp>
#include <gcufl/OrderedMap.hpp>
#include <string>
#include <string_view>


std::string gcufl::string::trimEnd(const std::string& string, const char character) noexcept {
	for (std::size_t i = string.size(); i > 0; --i)
		if (string[i - 1] != character)
			return string.substr(0, i);
	return "";
}

std::string gcufl::string::trimEnd(const std::string& string, std::string_view characters) noexcept {
	gcufl::OrderedMap<char, bool> charMap;
	for (const char character : characters)
		charMap[character] = true;
	for (std::size_t i = string.size(); i > 0; --i)
		if (!charMap[string[i - 1]])
			return string.substr(0, i);
	return "";
}

