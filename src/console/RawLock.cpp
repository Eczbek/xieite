#include <termios.h> // ECHO, TCSANOW, cfmakeraw, tcgetattr, termios
#include <unistd.h> // STDIN_FILENO
#include <xieite/console/RawLock.hpp> // xieite::console::RawLock

xieite::console::RawLock::RawLock(const bool echo) noexcept {
	tcgetattr(STDIN_FILENO, &cookedMode);
	termios rawMode = cookedMode;
	cfmakeraw(&rawMode);
	rawMode.c_lflag |= ECHO * echo;
	tcsetattr(STDIN_FILENO, TCSANOW, &rawMode);
}

xieite::console::RawLock::~RawLock() {
	tcsetattr(STDIN_FILENO, TCSANOW, &cookedMode);
}
