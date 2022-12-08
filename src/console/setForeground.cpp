#include <iostream>
#include <cstdlib>
#include <xieite/console/resetStyle.hpp>
#include <xieite/console/setForeground.hpp>
#include <xieite/graphics/Color.hpp>

void xieite::console::setForeground() noexcept {
	std::cout << "\x1b[38m";
}

void xieite::console::setForeground(const xieite::graphics::Color color) noexcept {
	static const int resetStyleAtExit = std::atexit(xieite::console::resetStyle);
	std::cout << "\x1b[38;2;" << static_cast<int>(color.red) << ';' << static_cast<int>(color.green) << ';' << static_cast<int>(color.blue) << 'm';
}
