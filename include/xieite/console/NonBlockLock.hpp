#pragma once
#include <fcntl.h> // fcntl, F_GETFL
#include <unistd.h> // STDIN_FILENO

namespace xieite::console {
	class NonBlockLock {
	private:
		const int blockingMode = fcntl(STDIN_FILENO, F_GETFL);

	public:
		NonBlockLock() noexcept;

		~NonBlockLock();
	};
}
