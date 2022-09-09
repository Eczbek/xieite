
#include <gcufl/io/locks/NonBlock.hpp>
#include <gcufl/io/locks/Raw.hpp>
#include <gcufl/io/readChar.hpp>
#include <iostream>


char gcufl::io::readChar(const char defaultChar) noexcept {
	gcufl::io::locks::Raw rawLock;
	gcufl::io::locks::NonBlock nonblockLock;
	char input = defaultChar;
	std::cin >> input;
	return input;
}
