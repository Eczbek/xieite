#pragma once

#include <fcntl.h>
#include <termios.h>
#include <unistd.h>

namespace xieite::console {
	class ModeLock {
	public:
		ModeLock() noexcept
		: blockingMode(fcntl(STDIN_FILENO, F_GETFL)), echo(false), canonical(false), signals(false), processing(false), blocking(true) {
			tcgetattr(STDIN_FILENO, &this->cookedMode);
			this->lock();
		}

		~ModeLock() {
			this->unlock();
		}

		void setEcho(const bool value) noexcept {
			this->echo = value;
			this->lock();
		}

		void setCanonical(const bool value) noexcept {
			this->canonical = value;
			this->lock();
		}

		void setSignals(const bool value) noexcept {
			this->signals = value;
			this->lock();
		}

		void setProcessing(const bool value) noexcept {
			this->processing = value;
			this->lock();
		}

		void setBlocking(const bool value) noexcept {
			this->blocking = value;
			this->lock();
		}

		void lock() noexcept {
			termios rawMode = this->cookedMode;
			rawMode.c_iflag &= ~((ICRNL * !this->signals) | (IXON * !this->signals));
			rawMode.c_lflag &= ~((ECHO * !this->echo) | (ICANON * !this->canonical) | (IEXTEN * !this->signals) | (ISIG * !this->signals));
			rawMode.c_oflag &= ~(OPOST * !this->processing);
			tcsetattr(STDIN_FILENO, TCSANOW, &rawMode);
			fcntl(STDIN_FILENO, TCSANOW, this->blockingMode | (O_NONBLOCK * !this->blocking));
		}

		void unlock() noexcept {
			this->echo = this->canonical = this->signals = this->processing = this->blocking = false;
			tcsetattr(STDIN_FILENO, TCSANOW, &this->cookedMode);
			fcntl(STDIN_FILENO, F_SETFL, this->blockingMode);
		}

	private:
		termios cookedMode;
		int blockingMode;
		bool echo;
		bool canonical;
		bool signals;
		bool processing;
		bool blocking;
	};
}
