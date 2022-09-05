#include <iostream>
#include <limits>
#include <sys/ioctl.h>
#include <gcufl/io.hpp>


gcufl::io::Raw::Raw(const bool echo) noexcept {
	if (rawLocks++)
		return;
	tcgetattr(STDIN_FILENO, &cooked);
	termios raw = cooked;
	cfmakeraw(&raw);
	raw.c_lflag |= ECHO * echo;
	tcsetattr(STDIN_FILENO, TCSANOW, &raw);
}

gcufl::io::Raw::~Raw() {
	if (!--rawLocks)
		tcsetattr(STDIN_FILENO, TCSANOW, &cooked);
}

gcufl::io::NonBlock::NonBlock() noexcept {
	if (!nonBlockLocks++)
		fcntl(STDIN_FILENO, F_SETFL, blocking | O_NONBLOCK);
}

gcufl::io::NonBlock::~NonBlock() {
	if (!--nonBlockLocks)
		fcntl(STDIN_FILENO, F_SETFL, blocking);
}

char gcufl::io::waitChar(const bool echo) noexcept {
	gcufl::io::Raw rawLock(echo);
	return std::cin.get();
}

char gcufl::io::readChar(const char defaultChar) noexcept {
	gcufl::io::Raw rawLock;
	gcufl::io::NonBlock nonblockLock;
	char input = defaultChar;
	std::cin >> input;
	return input;
}

std::string gcufl::io::readString(const std::size_t count, const char until) noexcept {
	gcufl::io::Raw rawLock;
	gcufl::io::NonBlock nonblockLock;
	std::string buffer;
	char input;
	while (buffer.size() <= count && std::cin >> input && input != until)
		buffer += input;
	return buffer;
}

void gcufl::io::putbackString(std::string_view string) noexcept {
	for (std::size_t i = string.size(); i > 0; --i)
		std::cin.putback(string[i - 1]);
}

gcufl::io::Position gcufl::io::getWindowSize() noexcept {
	winsize size;
	ioctl(STDIN_FILENO, TIOCGWINSZ, &size);
	return gcufl::io::Position(size.ws_col, size.ws_row);
}

gcufl::io::Position gcufl::io::cursor::getPosition() noexcept {
	gcufl::io::Raw rawLock;
	std::cout << "\033[6n";
	gcufl::io::Position position;
	std::scanf("\033[%d;%dR", &position.row, &position.column);
	return gcufl::io::Position(position.row - 1, position.column - 1);
}

void gcufl::io::cursor::setPosition(const gcufl::io::Position position) noexcept {
	std::cout << "\033[" << (position.row + 1) << ';' << (position.column + 1) << 'H';
}

void gcufl::io::cursor::move(const char direction, const int count) noexcept {
	std::cout << "\033[" << count << direction;
}
