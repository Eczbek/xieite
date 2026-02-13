#ifndef DETAIL_XTE_HEADER_SYS_ISATTY
#	define DETAIL_XTE_HEADER_SYS_ISATTY
#
#	include <cstdio>
#	include <stdio.h>
#	include "../preproc/platform.hpp"
#
#	if XTE_PLATFORM_UNIX
#		include <unistd.h>
#	elif XTE_PLATFORM_WINDOWS
#		include <windows.h>
#	else
#		warning unsupported platform
#	endif

namespace xte {
	[[nodiscard]] inline bool isatty(std::FILE* file) noexcept {
#	if XTE_PLATFORM_UNIX
		return ::isatty(::fileno(file));
#	elif XTE_PLATFORM_WINDOWS
		return ::_isatty(::_fileno(file));
#	else
		return false;
#	endif
	}
}

#endif
