#include <iostream> // std::cout
#include <cstdlib> // std::atexit
#include <xieite/console/resetStyle.hpp> // xieite::console::resetStyle
#include <xieite/console/setForeground.hpp> // xieite::console::setForeground
#include <xieite/graphics/Color.hpp> // xieite::graphics::Color

void xieite::console::setForeground() noexcept {
	std::cout << "\x1b[38m";
}

void xieite::console::setForeground(const xieite::graphics::Color color) noexcept {
	static const int resetStyleAtExit = std::atexit(xieite::console::resetStyle);
	std::cout << "\x1b[38;2;" << static_cast<int>(color.red) << ';' << static_cast<int>(color.green) << ';' << static_cast<int>(color.blue) << 'm';
}
