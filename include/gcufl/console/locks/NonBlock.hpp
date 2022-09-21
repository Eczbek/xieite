#pragma once

#include <cstddef>
#include <fcntl.h>
#include <unistd.h>


namespace gcufl::console::locks {
	class NonBlock {
	private:
		static std::size_t instancesCount;
		const int blockingMode = fcntl(STDIN_FILENO, F_GETFL);

	public:
		NonBlock() noexcept;

		~NonBlock();
	};
}
