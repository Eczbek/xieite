
#include <cstddef>
#include <gcufl/io/putBackString.hpp>
#include <iostream>
#include <string_view>


void gcufl::io::putBackString(std::string_view string) noexcept {
	for (std::size_t i = string.size(); i > 0; --i)
		std::cin.putback(string[i - 1]);
}
