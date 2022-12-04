#include <iostream>
#include <xieite/console/RawLock.hpp>
#include <xieite/console/nextKeyPress.hpp>

char xieite::console::nextKeyPress(const bool echo) noexcept {
	xieite::console::RawLock RawLock(echo);
	return std::cin.get();
}
