
#include <gcufl/console/locks/NonBlock.hpp>
#include <gcufl/console/locks/Raw.hpp>
#include <gcufl/console/readChar.hpp>
#include <unistd.h>


char gcufl::console::readChar(const char defaultChar) noexcept {
	gcufl::console::locks::Raw rawLock;
	gcufl::console::locks::NonBlock nonblockLock;
	char input = defaultChar;
	read(STDIN_FILENO, &input, 1);
	return input;
}
