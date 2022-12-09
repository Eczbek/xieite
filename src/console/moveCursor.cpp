#include <iostream> // std::cout
#include <xieite/console/moveCursor.hpp> // xieite::console::moveCursor

void xieite::console::move(const char direction, const int distance) noexcept {
	std::cout << "\x1b[" << distance << direction;
}
