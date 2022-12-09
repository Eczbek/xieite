#include <iostream> // std::cout
#include <xieite/console/clearLine.hpp> // xieite::console::clearLine

void xieite::console::clearLine() noexcept {
	std::cout << "\x1b[2K\r";
}
