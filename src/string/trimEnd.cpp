#include <cstddef>
#include <xieite/string/trimEnd.hpp>
#include <set>
#include <string>
#include <string_view>

std::string xieite::string::trimEnd(const std::string& string, const std::string_view characters) noexcept {
	const std::set<char> charSet(characters.begin(), characters.end());
	for (std::size_t i = string.size(); i--;)
		if (!charSet.contains(string[i]))
			return string.substr(0, i);
	return "";
}

std::string xieite::string::trimEnd(const std::string& string, const char character) noexcept {
	return xieite::string::trimEnd(string, std::string(1, character));
}
