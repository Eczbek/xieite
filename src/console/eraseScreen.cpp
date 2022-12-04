#include <iostream>
#include <xieite/console/eraseScreen.hpp>

void xieite::console::eraseScreen() noexcept {
	std::cout << "\x1b[2J";
}
