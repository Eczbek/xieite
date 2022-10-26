#include <cstddef>
#include <xieite/string/trimStart.hpp>
#include <set>
#include <string>
#include <string_view>

std::string xieite::string::trimStart(const std::string& string, const std::string_view characters) noexcept {
	std::set<char> charSet(characters.begin(), characters.end());
	const std::size_t stringSize = string.size();
	for (std::size_t i = 0; i < stringSize; ++i)
		if (!charSet.contains(string[i]))
			return string.substr(i);
	return "";
}

std::string xieite::string::trimStart(const std::string& string, const char character) noexcept {
	return xieite::string::trimStart(string, std::string(1, character));
}
