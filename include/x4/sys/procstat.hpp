#pragma once

#include "../pp/pltf.hpp"

#if X4PLTF_UNIX
#	include <sys/wait.h>
#endif

namespace x4 {
	[[nodiscard]] inline int procstat(int x) noexcept {
#if X4PLTF_UNIX
		if (WIFEXITED(x)) {
			return WEXITSTATUS(x);
		}
		if (WIFSIGNALED(x)) {
			return WTERMSIG(x);
		}
		if (WIFSTOPPED(x)) {
			return WSTOPSIG(x);
		}
#endif
		return x;
	}
}
