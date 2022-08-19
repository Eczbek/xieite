#include <iostream>
#include <limits>
#include <sys/ioctl.h>
#include <util/io>


util::io::RawLock::RawLock(const bool echo) noexcept {
	tcgetattr(STDIN_FILENO, &cooked);
	termios raw = cooked;
	cfmakeraw(&raw);
	if (echo)
		raw.c_lflag |= ECHO;
	tcsetattr(STDIN_FILENO, TCSANOW, &raw);
}

util::io::RawLock::~RawLock() {
	tcsetattr(STDIN_FILENO, TCSANOW, &cooked);
}

util::io::NonBlockLock::NonBlockLock() noexcept {
	fcntl(STDIN_FILENO, F_SETFL, blocking | O_NONBLOCK);
}

util::io::NonBlockLock::~NonBlockLock() {
	fcntl(STDIN_FILENO, F_SETFL, blocking);
}

char util::io::waitChar(const bool echo) noexcept {
	util::io::RawLock rawLock(echo);
	return std::cin.get();
}

char util::io::readChar(const char defaultChar) noexcept {
	util::io::RawLock rawLock;
	util::io::NonBlockLock nonblockLock;
	char input = defaultChar;
	std::cin >> input;
	return input;
}

std::string util::io::readString(const std::size_t count) noexcept {
	util::io::RawLock rawLock;
	util::io::NonBlockLock nonblockLock;
	std::string buffer;
	char input;
	while (buffer.size() <= count && std::cin >> input)
		buffer += input;
	return buffer;
}

void util::io::putbackString(std::string_view string) noexcept {
	for (std::size_t i = string.size(); i > 0; --i)
		std::cin.putback(string[i - 1]);
}

util::io::Position util::io::getWindowSize() noexcept {
	winsize size;
	ioctl(STDIN_FILENO, TIOCGWINSZ, &size);
	return util::io::Position(size.ws_col, size.ws_row);
}

util::io::Position util::io::cursor::getPos() noexcept {
	util::io::RawLock rawLock;
	std::cout << "\033[6n";
	util::io::Position position;
	std::scanf("\033[%d;%dR", &position.row, &position.column);
	return util::io::Position(position.row - 1, position.column - 1);
}

void util::io::cursor::setPos(const util::io::Position position) noexcept {
	std::cout << "\033[" << (position.row + 1) << ';' << (position.column + 1) << 'H';
}

void util::io::cursor::move(const char direction, const int count) noexcept {
	std::cout << "\033[" << count << direction;
}
