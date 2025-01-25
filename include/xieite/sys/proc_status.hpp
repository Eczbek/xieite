#pragma once

#include "../pp/pltf.hpp"

#if XIEITE_PLTF_TYPE_UNIX
#	include <sys/wait.h>
#endif

namespace xieite {
	[[nodiscard]] inline int proc_status(int status) noexcept {
#if XIEITE_PLTF_TYPE_UNIX
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
