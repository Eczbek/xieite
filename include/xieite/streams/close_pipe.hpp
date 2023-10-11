#ifndef XIEITE_HEADER_STREAMS_CLOSE_PIPE
#	define XIEITE_HEADER_STREAMS_CLOSE_PIPE

#	include "../macros/platform.hpp"

#	if XIEITE_PLATFORM_UNIX
#		include <cstdio>
#		include <stdio.h>

namespace xieite::streams {
	inline int closePipe(std::FILE* const pipe) noexcept {
		return pclose(pipe);
	}
}

#	elif XIEITE_PLATFORM_WINDOWS
#		include <cstdio>
#		include <stdio.h>

namespace xieite::streams {
	inline int closePipe(std::FILE* const pipe) noexcept {
		return _pclose(pipe);
	}
}

#	else
#		error "System not supported"
#	endif

#endif
