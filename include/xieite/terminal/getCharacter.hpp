#ifndef XIEITE_HEADER_TERMINAL_GETCHARACTER
#	define XIEITE_HEADER_TERMINAL_GETCHARACTER

#	include <xieite/macros/SYSTEM_TYPE.hpp>

#	if defined(XIEITE_SYSTEM_TYPE_LINUX)
#		include <unistd.h>
#		include <xieite/terminal/ModeLock.hpp>

namespace xieite::terminal {
	inline char getCharacter(const xieite::terminal::ModeLock& modeLock) {
		char input = 0;
		read(STDIN_FILENO, &input, 1);
		return input;
	}

	inline char getCharacter() {
		return xieite::terminal::getCharacter(xieite::terminal::ModeLock());
	}
}

#	else
#		error "System not supported"
#	endif

#endif
