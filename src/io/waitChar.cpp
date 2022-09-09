
#include <gcufl/io/locks/Raw.hpp>
#include <gcufl/io/waitChar.hpp>
#include <iostream>


char gcufl::io::waitChar(const bool echo) noexcept {
	gcufl::io::locks::Raw rawLock;
	return std::cin.get();
}
