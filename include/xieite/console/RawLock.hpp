#pragma once
#include <cstddef>
#include <termios.h>

namespace xieite::console {
	class RawLock {
	private:
		termios cookedMode;

	public:
		RawLock(const bool echo = false) noexcept;

		~RawLock();
	};
}
