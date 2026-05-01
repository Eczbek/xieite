#ifndef DETAIL_XTE_HEADER_SYS_AVAILABLE_MEMORY
#	define DETAIL_XTE_HEADER_SYS_AVAILABLE_MEMORY
#
#	include "../preproc/platform.hpp"
#	include "../util/numbers.hpp"
#
#	if XTE_PLATFORM_UNIX
#		include <unistd.h>
#		include "../sys/page_size.hpp"
#	elif XTE_PLATFORM_WINDOWS
#		include <windows.h>
#	else
#		warning unsupported platform
#	endif

namespace xte {
	[[nodiscard]] inline xte::uz available_memory() noexcept {
#	if XTE_PLATFORM_UNIX
		return static_cast<xte::uz>(::sysconf(_SC_AVPHYS_PAGES)) * xte::page_size();
#	elif XTE_PLATFORM_WINDOWS
		::MEMORYSTATUSEX status;
		status.dwLength = sizeof(status);
		::GlobalMemoryStatusEx(&status);
		return static_cast<xte::uz>(status.ullAvailPhys);
#	else
		return 0;
#	endif
	}
}

#endif
