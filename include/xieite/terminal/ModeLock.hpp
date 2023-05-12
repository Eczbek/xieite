#pragma once

#include <xieite/macros/SYSTEM_TYPE.hpp>

#if defined(XIEITE_SYSTEM_TYPE_LINUX)
#	include <fcntl.h>
#	include <termios.h>
#	include <unistd.h>

namespace xieite::terminal {
	class ModeLock final {
	public:
		ModeLock() noexcept
		: blockingMode(fcntl(STDIN_FILENO, F_GETFL)), blocking(true), echo(false), canonical(false), signals(false), processing(false), locked(true) {
			tcgetattr(STDIN_FILENO, &this->cookedMode);
			this->lock();
		}

		~ModeLock() {
			this->unlock();
		}

		void setBlocking(const bool value) noexcept {
			this->blocking = value;
			if (this->isLocked()) {
				this->lock();
			}
		}

		void setEcho(const bool value) noexcept {
			this->echo = value;
			if (this->isLocked()) {
				this->lock();
			}
		}

		void setCanonical(const bool value) noexcept {
			this->canonical = value;
			if (this->isLocked()) {
				this->lock();
			}
		}

		void setSignals(const bool value) noexcept {
			this->signals = value;
			if (this->isLocked()) {
				this->lock();
			}
		}

		void setProcessing(const bool value) noexcept {
			this->processing = value;
			if (this->isLocked()) {
				this->lock();
			}
		}

		void lock() noexcept {
			fcntl(STDIN_FILENO, F_SETFL, this->blockingMode | (O_NONBLOCK * !this->blocking));
			termios rawMode = this->cookedMode;
			rawMode.c_iflag &= ~((ICRNL * !this->signals) | (IXON * !this->signals));
			rawMode.c_lflag &= ~((ECHO * !this->echo) | (ICANON * !this->canonical) | (IEXTEN * !this->signals) | (ISIG * !this->signals));
			rawMode.c_oflag &= ~(OPOST * !this->processing);
			tcsetattr(STDIN_FILENO, TCSANOW, &rawMode);
			this->locked = true;
		}

		void unlock() noexcept {
			fcntl(STDIN_FILENO, F_SETFL, this->blockingMode);
			tcsetattr(STDIN_FILENO, TCSANOW, &this->cookedMode);
			this->locked = false;
		}

		[[nodiscard]]
		bool isLocked() noexcept {
			return this->locked;
		}

	private:
		termios cookedMode;
		int blockingMode;

		bool blocking;
		bool echo;
		bool canonical;
		bool signals;
		bool processing;

		bool locked;
	};
}

#else
#	error "System not supported"
#endif
