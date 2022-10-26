#include <termios.h>
#include <unistd.h>
#include <xieite/console/locks/Raw.hpp>

xieite::console::locks::Raw::Raw(const bool echo) noexcept {
	tcgetattr(STDIN_FILENO, &cookedMode);
	termios rawMode = cookedMode;
	cfmakeraw(&rawMode);
	rawMode.c_lflag |= ECHO * echo;
	tcsetattr(STDIN_FILENO, TCSANOW, &rawMode);
}

xieite::console::locks::Raw::~Raw() {
	tcsetattr(STDIN_FILENO, TCSANOW, &cookedMode);
}
