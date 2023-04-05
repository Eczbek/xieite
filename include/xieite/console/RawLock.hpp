#pragma once

#include <termios.h>
#include <unistd.h>

namespace xieite::console {
	class RawLock {
	private:
		bool locked;
		termios cookedMode;
		termios rawMode;

	public:
		RawLock() noexcept
		: locked(true) {
			tcgetattr(STDIN_FILENO, &this->cookedMode);
			this->rawMode = this->cookedMode;
			cfmakeraw(&this->rawMode);
			tcsetattr(STDIN_FILENO, TCSANOW, &rawMode);
		}

		~RawLock() {
			this->unlock();
		}

		void echo(const bool value) noexcept {
			this->rawMode.c_lflag |= (ECHO * value);
			tcsetattr(STDIN_FILENO, TCSANOW, &this->rawMode);
		}

		void canonical(const bool value) noexcept {
			this->rawMode.c_lflag |= (ICANON * value);
			tcsetattr(STDIN_FILENO, TCSANOW, &this->rawMode);
		}

		void signals(const bool value) noexcept {
			this->rawMode.c_iflag &= ~((ICRNL * value) | (IXON * value));
			this->rawMode.c_lflag &= ~((IEXTEN * value) | (ISIG * value));
			tcsetattr(STDIN_FILENO, TCSANOW, &this->rawMode);
		}

		void processing(const bool value) noexcept {
			this->rawMode.c_oflag |= (OPOST * value);
			tcsetattr(STDIN_FILENO, TCSANOW, &this->rawMode);
		}

		void unlock() noexcept {
			if (this->locked) {
				this->locked = false;
				tcsetattr(STDIN_FILENO, TCSANOW, &this->cookedMode);
			}
		}
	};
}
