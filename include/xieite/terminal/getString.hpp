#ifndef XIEITE_HEADER_TERMINAL_GETSTRING
#	define XIEITE_HEADER_TERMINAL_GETSTRING

#	include <xieite/macros/SYSTEM_TYPE.hpp>

#	ifdef XIEITE_SYSTEM_TYPE_LINUX
#		include <iostream>
#		include <string>
#		include <unistd.h>
#		include <xieite/system/bufferSize.hpp>
#		include <xieite/terminal/ModeLock.hpp>

namespace xieite::terminal {
	[[nodiscard]]
	inline std::string getString() noexcept {
		xieite::terminal::ModeLock modeLock;
		modeLock.setBlocking(false);
		std::string result;
		while (true) {
			std::string buffer = std::string(xieite::system::bufferSize, '\0');
			const ssize_t bytesRead = read(STDIN_FILENO, buffer.data(), buffer.size());
			if (bytesRead < 1) {
				break;
			}
			result += buffer;
		}
		return result;
	}
}

#	else
#		error "System not supported"
#	endif

#endif
