#ifndef XIEITE_HEADER__SYSTEM__CLOSE_FILE_PIPE
#	define XIEITE_HEADER__SYSTEM__CLOSE_FILE_PIPE

#	include "../macros/SYSTEM_TYPE.hpp"

#	if XIEITE__SYSTEM_TYPE__UNIX
#		include <cstdio>
#		include <stdio.h>

namespace xieite::system {
	inline int closeFilePipe(std::FILE* const pipe) noexcept {
		return ::pclose(pipe);
	}
}

#	elif XIEITE__SYSTEM_TYPE__WINDOWS
#		include <cstdio>
#		include <stdio.h>

namespace xieite::system {
	inline int closeFilePipe(std::FILE* const pipe) noexcept {
		return ::_pclose(pipe);
	}
}

#	else
#		error "System not supported"
#	endif

#endif
