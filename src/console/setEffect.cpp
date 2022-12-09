#include <iostream> // std::cout
#include <cstdlib> // std::atexit
#include <xieite/console/resetStyle.hpp>
#include <xieite/console/setEffect.hpp>

void xieite::console::setEffect(const int effect, const bool value) noexcept {
	static const int resetStyleAtExit = std::atexit(xieite::console::resetStyle);
	std::cout << "\x1b[" << (effect + !value * 20) << 'm';
}
