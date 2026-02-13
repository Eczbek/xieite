#ifndef DETAIL_XTE_HEADER_SYS_NPROC
#	define DETAIL_XTE_HEADER_SYS_NPROC
#
#	include "../preproc/platform.hpp"
#	include "../util/types.hpp"
#
#	if XTE_PLATFORM_UNIX
#		include <unistd.h>
#	elif XTE_PLATFORM_WINDOWS
#		include <windows.h>
#	else
#		warning unsupported platform
#	endif

namespace xte {
	[[nodiscard]] inline xte::uz nproc() noexcept {
#	if XTE_PLATFORM_UNIX
		return static_cast<xte::uz>(::sysconf(_SC_NPROCESSORS_ONLN));
#	elif XTE_PLATFORM_WINDOWS
		::SYSTEM_INFO info;
		::GetSystemInfo(&info);
		return static_cast<xte::uz>(info.dwNumberOfProcessors);
#	else
		return 0;
#	endif
	}
}

#endif
