#include <iostream> // std::cout
#include <xieite/console/clearScreen.hpp> // xieite::console::clearScreen

void xieite::console::clearScreen() noexcept {
	std::cout << "\x1b[2J\x1b[H";
}
