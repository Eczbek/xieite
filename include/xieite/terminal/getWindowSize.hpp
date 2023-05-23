#ifndef XIEITE_HEADER_TERMINAL_GETWINDOWSIZE
#	define XIEITE_HEADER_TERMINAL_GETWINDOWSIZE

#	include <xieite/macros/SYSTEM_TYPE.hpp>

#	if defined(XIEITE_SYSTEM_TYPE_LINUX)
#		include <sys/ioctl.h>
#		include <unistd.h>
#		include <xieite/terminal/Position.hpp>

namespace xieite::terminal {
	[[nodiscard]]
	inline xieite::terminal::Position getWindowSize() noexcept {
		winsize size;
		ioctl(STDIN_FILENO, TIOCGWINSZ, &size);
		return xieite::terminal::Position(size.ws_row, size.ws_col);
	}
}

#	else
#		error "System not supported"
#	endif

#endif
