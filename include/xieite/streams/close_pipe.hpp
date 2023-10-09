#ifndef XIEITE_HEADER__STREAMS__CLOSE_PIPE
#	define XIEITE_HEADER__STREAMS__CLOSE_PIPE

#	include "../macros/system_type.hpp"

#	if XIEITE__SYSTEM_TYPE__UNIX
#		include <cstdio>
#		include <stdio.h>

namespace xieite::streams {
	inline int closePipe(std::FILE* const pipe) noexcept {
		return ::pclose(pipe);
	}
}

#	elif XIEITE__SYSTEM_TYPE__WINDOWS
#		include <cstdio>
#		include <stdio.h>

namespace xieite::streams {
	inline int closePipe(std::FILE* const pipe) noexcept {
		return ::_pclose(pipe);
	}
}

#	else
#		error "System not supported"
#	endif

#endif
