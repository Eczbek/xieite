
#include <cstddef>
#include <gcufl/string/split.hpp>
#include <regex>
#include <string>
#include <string_view>
#include <vector>


std::vector<std::string> gcufl::string::split(const std::string& string, const char delimiter) noexcept {
	std::vector<std::string> segments;
	std::size_t i = 0;
	for (std::size_t j = 0; j < string.size(); ++j)
		if (string[j] == delimiter) {
			segments.push_back(string.substr(i, j - i));
			i = ++j;
		} 
	segments.push_back(string.substr(i));
	return segments;
}

std::vector<std::string> gcufl::string::split(const std::string& string, std::string_view delimiter) noexcept {
	std::vector<std::string> segments;
	std::size_t i = 0;
	for (std::size_t j = 0; j < string.size() - i; ++j)
		if (string.substr(j, delimiter.size()) == delimiter) {
			segments.push_back(string.substr(i, j - i));
			i = j += delimiter.size();
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
