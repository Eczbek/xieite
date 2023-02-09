#include <regex> // std::regex, std::sregex_token_iterator
#include <string> // std::string
#include <vector> // std::vector
#include <xieite/string/split.hpp>

std::vector<std::string> xieite::string::split(const std::string& string, const std::regex& delimiter) noexcept {
	return std::vector<std::string>(std::sregex_token_iterator(string.begin(), string.end(), delimiter, -1), std::sregex_token_iterator());
}
