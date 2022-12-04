#include <iostream>
#include <xieite/console/setForeground.hpp>
#include <xieite/console/StyleResetLock.hpp>

void xieite::console::setForeground(const int foreground, const bool dark) noexcept {
	static const xieite::console::StyleResetLock styleResetLock;
	std::cout << "\x1b[" << (foreground + 30 + dark * 60) << 'm';
}
