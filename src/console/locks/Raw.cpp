
#include <gcufl/console/locks/Raw.hpp>
#include <termios.h>
#include <unistd.h>


gcufl::console::locks::Raw::Raw(const bool echo) noexcept {
	tcgetattr(STDIN_FILENO, &cookedMode);
	termios rawMode = cookedMode;
	cfmakeraw(&rawMode);
	rawMode.c_lflag |= ECHO * echo;
	tcsetattr(STDIN_FILENO, TCSANOW, &rawMode);
}

gcufl::console::locks::Raw::~Raw() {
	tcsetattr(STDIN_FILENO, TCSANOW, &cookedMode);
}
