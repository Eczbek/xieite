
#include <cstddef>
#include <gcufl/string/trimEnd.hpp>
#include <map>
#include <string>
#include <string_view>


std::string gcufl::string::trimEnd(const std::string& string, const char character) noexcept {
	for (std::size_t i = string.size(); i--;)
		if (string[i] != character)
			return string.substr(0, i);
	return "";
}

std::string gcufl::string::trimEnd(const std::string& string, const std::string_view characters) noexcept {
	std::map<char, bool> charMap;
	for (const char character : characters)
		charMap[character] = true;
	for (std::size_t i = string.size(); i--;)
		if (!charMap[string[i]])
			return string.substr(0, i);
	return "";
}

