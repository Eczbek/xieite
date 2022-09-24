
#include <cstddef>
#include <gcufl/console/putBackString.hpp>
#include <iostream>
#include <string_view>


void gcufl::console::putBackString(const std::string_view string) noexcept {
	for (std::size_t i = string.size(); i--;)
		std::cin.putback(string[i]);
}
