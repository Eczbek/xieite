#include <iostream> // std::cout
#include <xieite/console/resetStyle.hpp>

void xieite::console::resetStyle() noexcept {
	std::cout << "\x1b[0m";
}
