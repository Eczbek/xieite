#pragma once
#include <fcntl.h> // F_SETFL, O_NONBLOCK, fcntl
#include <unistd.h> // STDIN_FILENO

namespace xieite::console {
	class NonBlockLock {
	private:
		const int blockingMode = fcntl(STDIN_FILENO, F_GETFL);

	public:
		NonBlockLock() noexcept {
			fcntl(STDIN_FILENO, F_SETFL, blockingMode | O_NONBLOCK);
		}

		~NonBlockLock() {
			fcntl(STDIN_FILENO, F_SETFL, blockingMode);
		}
	};
}
