#pragma once

#include <termios.h>
#include <unistd.h>

namespace xieite::console {
	class RawLock {
	private:
		termios cookedMode;

	public:
		RawLock(const bool echo = false) noexcept {
			tcgetattr(STDIN_FILENO, &this->cookedMode);
			termios rawMode = this->cookedMode;
			cfmakeraw(&rawMode);
			rawMode.c_lflag |= ECHO * echo;
			tcsetattr(STDIN_FILENO, TCSANOW, &rawMode);
		}

		~RawLock() {
			tcsetattr(STDIN_FILENO, TCSANOW, &this->cookedMode);
		}
	};
}
