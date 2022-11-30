#include <cstddef>
#include <string>
#include <unordered_set>
#include <xieite/string/trimEnd.hpp>

std::string xieite::string::trimEnd(const std::string& string, const char character) noexcept {
	for (std::size_t i = string.size(); i--;)
		if (string[i] != character)
			return string.substr(0, i);
	return "";
}

std::string xieite::string::trimEnd(const std::string& string, const std::unordered_set<char>& characters) noexcept {
	for (std::size_t i = string.size(); i--;)
		if (!characters.contains(string[i]))
			return string.substr(0, i);
	return "";
}
