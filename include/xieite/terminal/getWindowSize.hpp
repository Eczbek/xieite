#pragma once

#include <sys/ioctl.h>
#include <unistd.h>
#include <xieite/terminal/Position.hpp>

namespace xieite::terminal {
	[[nodiscard]]
	inline xieite::terminal::Position getWindowSize() noexcept {
		winsize size;
		ioctl(STDIN_FILENO, TIOCGWINSZ, &size);
		return xieite::terminal::Position(size.ws_row, size.ws_col);
	}
}
