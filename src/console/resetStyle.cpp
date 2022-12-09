#include <iostream> // std::cout
#include <xieite/console/resetStyle.hpp> // xieite::console::resetStyle

void xieite::console::resetStyle() noexcept {
	std::cout << "\x1b[0m";
}
