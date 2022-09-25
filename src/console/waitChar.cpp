
#include <gcufl/console/locks/Raw.hpp>
#include <gcufl/console/waitChar.hpp>
#include <iostream>


char gcufl::console::waitChar(const bool echo) noexcept {
	gcufl::console::locks::Raw rawLock(echo);
	return std::cin.get();
}
