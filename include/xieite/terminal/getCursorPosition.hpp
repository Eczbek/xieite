#ifndef XIEITE_HEADER_TERMINAL_GETCURSORPOSITION
#	define XIEITE_HEADER_TERMINAL_GETCURSORPOSITION

#	include <xieite/macros/SYSTEM_TYPE.hpp>

#	ifdef XIEITE_SYSTEM_TYPE_LINUX
#		include <cstdio>
#		include <iostream>
#		include <xieite/terminal/ModeLock.hpp>
#		include <xieite/terminal/Position.hpp>

namespace xieite::terminal {
	[[nodiscard]]
	inline xieite::terminal::Position getCursorPosition() {
		xieite::terminal::ModeLock modeLock;
		std::cout << "\u001b[6n";
		xieite::terminal::Position position = xieite::terminal::Position(0, 0);
		std::scanf("\u001b[%i;%iR", &position.row, &position.column);
		return xieite::terminal::Position(position.row - 1, position.column - 1);
	}
}

#	else
#		error "System not supported"
#	endif

#endif
