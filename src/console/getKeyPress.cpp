#include <iostream> // std::cin
#include <xieite/console/RawLock.hpp>
#include <xieite/console/getKeyPress.hpp>

char xieite::console::getKeyPress(const bool echo) noexcept {
	xieite::console::RawLock RawLock(echo);
	return std::cin.get();
}
