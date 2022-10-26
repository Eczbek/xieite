#include <iostream>
#include <xieite/console/eraseLine.hpp>

void xieite::console::eraseLine(const int erasor) noexcept {
	std::cout << "\x1b[" << erasor << 'K';
}
