#include <string>
#include <string_view>
#include <xieite/string/repeat.hpp>

std::string xieite::string::repeat(const std::string_view string, std::size_t count) noexcept {
	std::string result;
	while (count--)
		result += string;
	return result;
}
