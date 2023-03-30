#pragma once

#include <termios.h>
#include <unistd.h>

namespace xieite::console {
	class RawLock {
	private:
		static bool locked = false;
		static termios cookedMode;

	public:
		RawLock(const bool echo = true) noexcept {
			if (!this->locked) {
				this->locked = true;
				tcgetattr(STDIN_FILENO, &this->cookedMode);
				termios rawMode = this->cookedMode;
				cfmakeraw(&rawMode);
				rawMode.c_lflag &= ~(ICANON | (ECHO * echo));
				tcsetattr(STDIN_FILENO, TCSANOW, &rawMode);
			}
		}

		~RawLock() {
			this->unlock();
		}

		void unlock() noexcept {
			if (this->locked) {
				this->locked = false;
				tcsetattr(STDIN_FILENO, TCSANOW, &this->cookedMode);
			}
		}
	};
}
