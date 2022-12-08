#include <iostream>
#include <xieite/console/clearScreen.hpp>

void xieite::console::clearScreen() noexcept {
	std::cout << "\x1b[2J\x1b[H";
}
