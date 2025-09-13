#ifndef DETAIL_XIEITE_HEADER_SYS_ISATTY
#	define DETAIL_XIEITE_HEADER_SYS_ISATTY
#
#	include <cstdio>
#	include <stdio.h>
#	include "../pp/platform.hpp"
#
#	if XIEITE_PLATFORM_TYPE_UNIX
#		include <unistd.h>
#	elif XIEITE_PLATFORM_TYPE_WINDOWS
#		include <windows.h>
#	else
#		warning unsupported platform
#	endif

namespace xieite {
	[[nodiscard]] inline bool isatty(std::FILE* file) noexcept {
#	if XIEITE_PLATFORM_TYPE_UNIX
		return ::isatty(::fileno(file));
#	elif XIEITE_PLATFORM_TYPE_WINDOWS
		return ::_isatty(::_fileno(file));
#	else
		return false;
#	endif
	}
}

#endif
