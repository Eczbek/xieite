#pragma once
#include <cstddef>
#include <fcntl.h>
#include <unistd.h>

namespace xieite::console {
	class NonBlockLock {
	private:
		const int blockingMode = fcntl(STDIN_FILENO, F_GETFL);

	public:
		NonBlockLock() noexcept;

		~NonBlockLock();
	};
}
