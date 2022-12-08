#include <iostream>
#include <xieite/console/setBackground.hpp>
#include <xieite/console/StyleResetLock.hpp>

void xieite::console::setBackground(const int background) noexcept {
	static const xieite::console::StyleResetLock styleResetLock;
	std::cout << "\x1b[" << (background + 10) << 'm';
}
