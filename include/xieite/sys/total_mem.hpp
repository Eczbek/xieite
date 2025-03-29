#ifndef DETAIL_XIEITE_HEADER_SYS_TOTAL_MEM
#	define DETAIL_XIEITE_HEADER_SYS_TOTAL_MEM
#
#	include <cstddef>
#	include <memory>
#	include "../pp/platform.hpp"
#	include "../sys/page_mem.hpp"
#
#	if XIEITE_PLATFORM_TYPE_UNIX
#		include <unistd.h>
#	elif XIEITE_PLATFORM_TYPE_WINDOWS
#		include <windows.h>
#	else
#		warning unsupported platform
#	endif

namespace xieite {
	[[nodiscard]] inline std::size_t total_mem() noexcept {
#	if XIEITE_PLATFORM_TYPE_UNIX
		return static_cast<std::size_t>(::sysconf(_SC_PHYS_PAGES)) * xieite::page_mem();
#	elif XIEITE_PLATFORM_TYPE_WINDOWS
		::MEMORYSTATUSEX status;
		status.dwLength = sizeof(status);
		::GlobalMemoryStatusEx(std::addressof(status));
		return static_cast<std::size_t>(status.ullTotalPhys);
#	else
		return 0;
#	endif
	}
}

#endif
