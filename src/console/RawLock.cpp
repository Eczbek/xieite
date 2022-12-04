#include <termios.h>
#include <unistd.h>
#include <xieite/console/RawLock.hpp>

xieite::console::RawLock::RawLock(const bool echo) noexcept {
	tcgetattr(STDIN_FILENO, &cookedMode);
	termios RawLockMode = cookedMode;
	cfmakeraw(&RawLockMode);
	RawLockMode.c_lflag |= ECHO * echo;
	tcsetattr(STDIN_FILENO, TCSANOW, &RawLockMode);
}

xieite::console::RawLock::~RawLock() {
	tcsetattr(STDIN_FILENO, TCSANOW, &cookedMode);
}
