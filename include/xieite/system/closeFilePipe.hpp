#ifndef XIEITE_HEADER_SYSTEM_CLOSEFILEPIPE
#	define XIEITE_HEADER_SYSTEM_CLOSEFILEPIPE

#	include "../macros/SYSTEM_TYPE.hpp"

#	if XIEITE_SYSTEM_TYPE_UNIX
#		include <cstdio>
#		include <stdio.h>

namespace xieite::system {
	inline int closeFilePipe(std::FILE* const pipe) noexcept {
		return ::pclose(pipe);
	}
}

#	elif XIEITE_SYSTEM_TYPE_WINDOWS
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
