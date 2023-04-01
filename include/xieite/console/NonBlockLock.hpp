#pragma once

#include <fcntl.h>
#include <unistd.h>

namespace xieite::console {
	class NonBlockLock {
	private:
		bool locked;
		int blockingMode;

	public:
		NonBlockLock() noexcept
		: locked(true), blockingMode(fcntl(STDIN_FILENO, F_GETFL)) {
			fcntl(STDIN_FILENO, F_SETFL, this->blockingMode | O_NONBLOCK);
		}

		~NonBlockLock() {
			this->unlock();
		}

		void unlock() noexcept {
			if (this->locked) {
				this->locked = false;
				fcntl(STDIN_FILENO, F_SETFL, this->blockingMode);
			}
		}
	};
}
