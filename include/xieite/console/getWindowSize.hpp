#pragma once

#include <sys/ioctl.h>
#include <unistd.h>
#include <xieite/console/Position.hpp>

namespace xieite::console {
	[[nodiscard]]
	inline xieite::console::Position getWindowSize() noexcept {
		winsize size;
		ioctl(STDIN_FILENO, TIOCGWINSZ, &size);
		return xieite::console::Position(size.ws_row, size.ws_col);
	}
}
