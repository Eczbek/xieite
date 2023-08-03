#ifndef XIEITE_HEADER_SYSTEM_OPENFILEPIPE
#	define XIEITE_HEADER_SYSTEM_OPENFILEPIPE

#	include "../macros/SYSTEM_TYPE.hpp"

#	if XIEITE_SYSTEM_TYPE_UNIX
#		include <cstdio>
#		include <stdio.h>

namespace xieite::system {
	inline std::FILE* openFilePipe(const char* const command, const char* const mode) noexcept {
		return ::popen(command, mode);
	}
}

#	elif XIEITE_SYSTEM_TYPE_WINDOWS
#		include <cstdio>
#		include <stdio.h>

namespace xieite::system {
	inline std::FILE* openFilePipe(const char* const command, const char* const mode) noexcept {
		return ::_popen(command, mode);
	}
}

#	else
#		error "System not supported"
#	endif

#endif
