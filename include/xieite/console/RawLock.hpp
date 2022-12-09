#pragma once
#include <termios.h> // termios

namespace xieite::console {
	class RawLock {
	private:
		termios cookedMode;

	public:
		RawLock(const bool echo = false) noexcept;

		~RawLock();
	};
}
