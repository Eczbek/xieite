#include <iostream>
#include <xieite/console/locks/Raw.hpp>
#include <xieite/console/waitChar.hpp>

char xieite::console::waitChar(const bool echo) noexcept {
	xieite::console::locks::Raw rawLock(echo);
	return std::cin.get();
}
