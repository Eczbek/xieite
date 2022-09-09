#pragma once

#include <cstddef>
#include <termios.h>


namespace gcufl::io::locks {
	class Raw {
	private:
		static std::size_t instancesCount;
		termios cookedMode;

	public:
		Raw(const bool echo = false) noexcept;

		~Raw();
	};
}
