#pragma once
#include <sys/ioctl.h> // TIOCGWINSZ, ioctl, winsize
#include <unistd.h> // STDIN_FILENO
#include <xieite/console/CursorPosition.hpp>

namespace xieite::console {
	[[nodiscard]]
	inline xieite::console::CursorPosition getWindowSize() noexcept {
		winsize size;
		ioctl(STDIN_FILENO, TIOCGWINSZ, &size);
		return xieite::console::CursorPosition(size.ws_row, size.ws_col);
	}
}
