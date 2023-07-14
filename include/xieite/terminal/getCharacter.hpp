#ifndef XIEITE_HEADER_TERMINAL_GETCHARACTER
#	define XIEITE_HEADER_TERMINAL_GETCHARACTER

#	include <xieite/macros/SYSTEM_TYPE.hpp>

#	ifdef XIEITE_SYSTEM_TYPE_LINUX
#		include <unistd.h>
#		include <xieite/terminal/ModeLock.hpp>

namespace xieite::terminal {
	inline char getCharacter(const xieite::terminal::ModeLock& modeLock = xieite::terminal::ModeLock()) {
		char input = 0;
		read(STDIN_FILENO, &input, 1);
		return input;
	}
}

#	else
#		error "System not supported"
#	endif

#endif
