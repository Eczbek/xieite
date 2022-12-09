#include <iostream> // std::cout
#include <xieite/console/clearLine.hpp>

void xieite::console::clearLine() noexcept {
	std::cout << "\x1b[2K\r";
}
