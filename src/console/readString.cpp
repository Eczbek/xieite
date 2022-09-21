
#include <gcufl/console/locks/NonBlock.hpp>
#include <gcufl/console/locks/Raw.hpp>
#include <gcufl/console/readString.hpp>
#include <ios>
#include <string>
#include <unistd.h>


std::string gcufl::console::readString(const std::streamsize count, const char until) noexcept {
	gcufl::console::locks::Raw rawLock;
	gcufl::console::locks::NonBlock nonblockLock;
	std::string buffer;
	char input;
	while (buffer.size() <= count && read(STDIN_FILENO, &input, 1) == 1 && input != until)
		buffer += input;
	return buffer;
}
