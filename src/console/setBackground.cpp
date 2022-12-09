#include <iostream> // std::cout
#include <cstdlib> // std::atexit
#include <xieite/console/resetStyle.hpp>
#include <xieite/console/setBackground.hpp>
#include <xieite/graphics/Color.hpp>

void xieite::console::setBackground() noexcept {
	std::cout << "\x1b[48m";
}

void xieite::console::setBackground(const xieite::graphics::Color color) noexcept {
	static const int resetStyleAtExit = std::atexit(xieite::console::resetStyle);
	std::cout << "\x1b[48;2;" << static_cast<int>(color.red) << ';' << static_cast<int>(color.green) << ';' << static_cast<int>(color.blue) << 'm';
}
