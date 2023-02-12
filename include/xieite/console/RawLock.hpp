#pragma once
#include <termios.h> // ECHO, TCSANOW, cfmakeraw, tcgetattr, termios
#include <unistd.h> // STDIN_FILENO

namespace xieite::console {
	class RawLock {
	private:
		termios cookedMode;

	public:
		inline RawLock(const bool echo = false) noexcept {
			tcgetattr(STDIN_FILENO, &cookedMode);
			termios rawMode = cookedMode;
			cfmakeraw(&rawMode);
			rawMode.c_lflag |= ECHO * echo;
			tcsetattr(STDIN_FILENO, TCSANOW, &rawMode);
		}

		inline ~RawLock() {
			tcsetattr(STDIN_FILENO, TCSANOW, &cookedMode);
		}
	};
}
