#include <iostream>
#include <xieite/console/eraseScreen.hpp>

void xieite::console::eraseScreen(const int erasor) noexcept {
	std::cout << "\x1b[" << erasor << 'J';
}
