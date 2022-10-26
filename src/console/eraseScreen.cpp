#include <xieite/console/eraseScreen.hpp>
#include <iostream>

void xieite::console::eraseScreen(const int erasor) noexcept {
	std::cout << "\x1b[" << erasor << 'J';
}
