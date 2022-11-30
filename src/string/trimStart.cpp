#include <cstddef>
#include <set>
#include <string>
#include <xieite/string/trimStart.hpp>

std::string xieite::string::trimStart(const std::string& string, const char character) noexcept {
	const std::size_t stringSize = string.size();
	for (std::size_t i = 0; i < stringSize; ++i)
		if (string[i] != character)
			return string.substr(i);
	return "";
}

std::string xieite::string::trimStart(const std::string& string, const std::set<char>& characters) noexcept {
	const std::size_t stringSize = string.size();
	for (std::size_t i = 0; i < stringSize; ++i)
		if (!characters.contains(string[i]))
			return string.substr(i);
	return "";
}
