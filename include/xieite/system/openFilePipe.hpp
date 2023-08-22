#ifndef XIEITE_HEADER__SYSTEM__OPEN_FILE_PIPE
#	define XIEITE_HEADER__SYSTEM__OPEN_FILE_PIPE

#	include "../macros/SYSTEM_TYPE.hpp"

#	if XIEITE__SYSTEM_TYPE__UNIX
#		include <cstdio>
#		include <stdio.h>

namespace xieite::system {
	[[nodiscard]] inline std::FILE* openFilePipe(const char* const command, const char* const mode) noexcept {
		return ::popen(command, mode);
	}
}

#	elif XIEITE__SYSTEM_TYPE__WINDOWS
#		include <cstdio>
#		include <stdio.h>

namespace xieite::system {
	[[nodiscard]] inline std::FILE* openFilePipe(const char* const command, const char* const mode) noexcept {
		return ::_popen(command, mode);
	}
}

#	else
#		error "System not supported"
#	endif

#endif
