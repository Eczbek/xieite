#include <xieite/console/eraseLine.hpp>
#include <iostream>

void xieite::console::eraseLine(const int erasor) noexcept {
	std::cout << "\x1b[" << erasor << 'K';
}
