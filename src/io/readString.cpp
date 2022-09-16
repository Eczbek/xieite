
#include <gcufl/io/locks/NonBlock.hpp>
#include <gcufl/io/locks/Raw.hpp>
#include <gcufl/io/readString.hpp>
#include <ios>
#include <string>
#include <unistd.h>


std::string gcufl::io::readString(const std::streamsize count, const char until) noexcept {
	gcufl::io::locks::Raw rawLock;
	gcufl::io::locks::NonBlock nonblockLock;
	std::string buffer;
	char input;
	while (buffer.size() <= count && read(STDIN_FILENO, &input, 1) == 1 && input != until)
		buffer += input;
	return buffer;
}
