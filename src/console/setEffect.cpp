#include <iostream>
#include <xieite/console/setEffect.hpp>
#include <xieite/console/StyleResetLock.hpp>

void xieite::console::setEffect(const int effect) noexcept {
	static const xieite::console::StyleResetLock styleResetLock;
	std::cout << "\x1b[" << effect << 'm';
}
