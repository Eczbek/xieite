#include <iostream>
#include <xieite/console/eraseLine.hpp>

void xieite::console::eraseLine() noexcept {
	std::cout << "\x1b[2K";
}
