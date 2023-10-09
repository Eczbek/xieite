#ifndef XIEITE_HEADER__STREAMS__OPEN_PIPE
#	define XIEITE_HEADER__STREAMS__OPEN_PIPE

#	include "../macros/system_type.hpp"

#	if XIEITE__SYSTEM_TYPE__UNIX
#		include <cstdio>
#		include <stdio.h>

namespace xieite::streams {
	[[nodiscard]] inline std::FILE* openPipe(const char* const command, const char* const mode) noexcept {
		return ::popen(command, mode);
	}
}

#	elif XIEITE__SYSTEM_TYPE__WINDOWS
#		include <cstdio>
#		include <stdio.h>

namespace xieite::streams {
	[[nodiscard]] inline std::FILE* openPipe(const char* const command, const char* const mode) noexcept {
		return ::_popen(command, mode);
	}
}

#	else
#		error "System not supported"
#	endif

#endif
