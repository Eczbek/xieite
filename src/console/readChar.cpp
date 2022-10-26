#include <unistd.h>
#include <xieite/console/locks/NonBlock.hpp>
#include <xieite/console/locks/Raw.hpp>
#include <xieite/console/readChar.hpp>

char xieite::console::readChar() noexcept {
	xieite::console::locks::Raw rawLock;
	xieite::console::locks::NonBlock nonblockLock;
	char input = 0;
	read(STDIN_FILENO, &input, 1);
	return input;
}
