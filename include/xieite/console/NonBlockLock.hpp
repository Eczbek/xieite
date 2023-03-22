#pragma once

#include <fcntl.h>
#include <unistd.h>

namespace xieite::console {
	class NonBlockLock {
	private:
		int blockingMode;

	public:
		NonBlockLock() noexcept
		: blockingMode(fcntl(STDIN_FILENO, F_GETFL)) {
			fcntl(STDIN_FILENO, F_SETFL, this->blockingMode | O_NONBLOCK);
		}

		~NonBlockLock() {
			fcntl(STDIN_FILENO, F_SETFL, this->blockingMode);
		}
	};
}
