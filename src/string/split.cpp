
#include <cstddef>
#include <gcufl/string/split.hpp>
#include <regex>
#include <string>
#include <string_view>
#include <vector>


std::vector<std::string> gcufl::string::split(const std::string& string, const char delimiter) noexcept {
	std::vector<std::string> segments;
	const std::size_t stringSize = string.size();
	std::size_t i = 0;
	for (std::size_t j = 0; j < stringSize; ++j)
		if (string[j] == delimiter) {
			segments.push_back(string.substr(i, j - i));
			i = ++j;
		} 
	segments.push_back(string.substr(i));
	return segments;
}

std::vector<std::string> gcufl::string::split(const std::string& string, std::string_view delimiter) noexcept {
	std::vector<std::string> segments;
	const std::size_t stringSize = string.size();
	const std::size_t delimiterSize = delimiter.size();
	std::size_t i = 0;
	for (std::size_t j = 0; j < stringSize - i; ++j)
		if (string.substr(j, delimiterSize) == delimiter) {
			segments.push_back(string.substr(i, j - i));
			i = j += delimiterSize;
		}
	segments.push_back(string.substr(i));
	return segments;
}

std::vector<std::string> gcufl::string::split(const std::string& string, const std::regex& delimiter) noexcept {
	return std::vector<std::string> {
		std::sregex_token_iterator(string.begin(), string.end(), delimiter, -1),
		std::sregex_token_iterator()
	};
}
