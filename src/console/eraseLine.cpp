
#include <gcufl/console/eraseLine.hpp>
#include <iostream>

void gcufl::console::eraseLine(const int erasor) noexcept {
	std::cout << "\x1b[" << erasor << 'K';
}
