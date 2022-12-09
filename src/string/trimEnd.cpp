#include <cstddef> // std::size_t
#include <string> // std::string
#include <unordered_set> // std::unordered_set
#include <xieite/string/trimEnd.hpp> // xieite::string::trimEnd

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
