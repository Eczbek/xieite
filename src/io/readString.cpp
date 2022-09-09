
#include <gcufl/io/locks/NonBlock.hpp>
#include <gcufl/io/locks/Raw.hpp>
#include <gcufl/io/readString.hpp>
#include <ios>
#include <iostream>
#include <string>


std::string gcufl::io::readString(const std::streamsize count, const char until) noexcept {
	gcufl::io::locks::Raw rawLock;
	gcufl::io::locks::NonBlock nonblockLock;
	std::string buffer;
	char input;
	while (buffer.size() <= count && std::cin >> input && input != until)
		buffer += input;
	return buffer;
}
