#ifndef DETAIL_XIEITE_HEADER_SYS_PROCESS_STATUS
#	define DETAIL_XIEITE_HEADER_SYS_PROCESS_STATUS
#
#	include "../pp/platform.hpp"
#
#	if XIEITE_PLATFORM_TYPE_UNIX
#		include <sys/wait.h>
#	endif

namespace xieite {
	[[nodiscard]] inline int process_status(int status) noexcept {
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
