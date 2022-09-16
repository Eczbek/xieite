
#include <gcufl/io/locks/NonBlock.hpp>
#include <gcufl/io/locks/Raw.hpp>
#include <gcufl/io/readChar.hpp>
#include <unistd.h>


char gcufl::io::readChar(const char defaultChar) noexcept {
	gcufl::io::locks::Raw rawLock;
	gcufl::io::locks::NonBlock nonblockLock;
	char input = defaultChar;
	read(STDIN_FILENO, &input, 1);
	return input;
}
