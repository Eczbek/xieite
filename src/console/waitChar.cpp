#include <xieite/console/locks/Raw.hpp>
#include <xieite/console/waitChar.hpp>
#include <iostream>

char xieite::console::waitChar(const bool echo) noexcept {
	xieite::console::locks::Raw rawLock(echo);
	return std::cin.get();
}
