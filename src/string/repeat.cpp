#include <cstddef> // std::size_t
#include <string> // std::string
#include <string_view> // std::string_view
#include <xieite/string/repeat.hpp> // xieite::string::repeat

std::string xieite::string::repeat(const std::string_view string, std::size_t count) noexcept {
	std::string result;
	while (count--)
		result += string;
	return result;
}
