
#include <cstddef>
#include <gcufl/string/trimStart.hpp>
#include <gcufl/OrderedMap.hpp>
#include <string>
#include <string_view>


std::string gcufl::string::trimStart(const std::string& string, const char character) noexcept {
	const std::size_t stringSize = string.size();
	for (std::size_t i = 0; i < stringSize; ++i)
		if (string[i] != character)
			return string.substr(i);
	return "";
}

std::string gcufl::string::trimStart(const std::string& string, std::string_view characters) noexcept {
	gcufl::OrderedMap<char, bool> charMap;
	for (const char character : characters)
		charMap[character] = true;
	const std::size_t stringSize = string.size();
	for (std::size_t i = 0; i < stringSize; ++i)
		if (!charMap[string[i]])
			return string.substr(i);
	return "";
}
