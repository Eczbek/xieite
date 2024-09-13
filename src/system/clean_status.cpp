module;

#include <xieite/platform.hpp>

#if XIEITE_PLATFORM_TYPE_UNIX
#	include <sys/wait.h>
#endif

export module xieite:system.cleanStatus;

export namespace xieite::system {
	int cleanStatus(const int status) noexcept {
#if XIEITE_PLATFORM_TYPE_UNIX
		if (WIFEXITED(status)) {
			return WEXITSTATUS(status);
		}
		if (WIFSIGNALED(status)) {
			return WTERMSIG(status);
		}
		if (WIFSTOPPED(status)) {
			return WSTOPSIG(status);
		}
#endif
		return status;
	}
}
