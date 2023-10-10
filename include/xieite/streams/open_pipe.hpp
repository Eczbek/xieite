#pragma once

#include "../macros/platform.hpp"

#if XIEITE_PLATFORM_UNIX
#	include <cstdio>
#	include <stdio.h>

namespace xieite::streams {
	[[nodiscard]] inline std::FILE* openPipe(const char* const command, const char* const mode) noexcept {
		return popen(command, mode);
	}
}

#elif XIEITE_PLATFORM_WINDOWS
#	include <cstdio>
#	include <stdio.h>

namespace xieite::streams {
	[[nodiscard]] inline std::FILE* openPipe(const char* const command, const char* const mode) noexcept {
		return _popen(command, mode);
	}
}

#else
#	error "System not supported"
#endif
