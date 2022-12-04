#include <iostream>
#include <xieite/console/moveCursor.hpp>

void xieite::console::move(const char direction, const int distance) noexcept {
	std::cout << "\x1b[" << distance << direction;
}
