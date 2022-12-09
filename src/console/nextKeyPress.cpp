#include <iostream> // std::cin
#include <xieite/console/RawLock.hpp> // xieite::console::RawLock
#include <xieite/console/nextKeyPress.hpp> // xieite::console::nextKeyPress

char xieite::console::nextKeyPress(const bool echo) noexcept {
	xieite::console::RawLock RawLock(echo);
	return std::cin.get();
}
