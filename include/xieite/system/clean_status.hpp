#ifndef XIEITE_HEADER_SYSTEM_CLEAN_STATUS
#	define XIEITE_HEADER_SYSTEM_CLEAN_STATUS

#	include "../macros/platform.hpp"

#	if XIEITE_PLATFORM_TYPE_UNIX
#		include <sys/wait.h>
#	endif

namespace xieite::system {
	inline int cleanStatus(const int status) noexcept {
#	if XIEITE_PLATFORM_TYPE_UNIX
		if (WIFEXITED(status)) {
			return WEXITSTATUS(status);
		}
		if (WIFSIGNALED(status)) {
			return WTERMSIG(status);
		}
		if (WIFSTOPPED(status)) {
			return WSTOPSIG(status);
		}
#	endif
		return status;
	}
}

#endif
