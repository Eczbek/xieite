#pragma once
#include <cstddef>
#include <termios.h>

namespace xieite::console::locks {
	class Raw {
	private:
		termios cookedMode;

	public:
		Raw(const bool echo = false) noexcept;

		~Raw();
	};
}
