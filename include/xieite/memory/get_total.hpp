#ifndef XIEITE_HEADER_MEMORY_GET_TOTAL
#	define XIEITE_HEADER_MEMORY_GET_TOTAL

#	include <cstddef>
#	include "../macros/platform.hpp"

#	if XIEITE_PLATFORM_TYPE_UNIX
#		include <unistd.h>
#		include "../memory/get_page_size.hpp"
#	elif XIEITE_PLATFORM_TYPE_WINDOWS
#		include <windows.h>
#	else
#		warning "Platform not supported"
#	endif

namespace xieite::memory {
	[[nodiscard]] inline std::size_t getTotal() noexcept {
#	if XIEITE_PLATFORM_TYPE_UNIX
		return static_cast<std::size_t>(::sysconf(_SC_PHYS_PAGES)) * xieite::memory::getPageSize();
#	elif XIEITE_PLATFORM_TYPE_WINDOWS
		MEMORYSTATUSEX status;
		status.dwLength = sizeof(status);
		::GlobalMemoryStatusEx(&status);
		return status.ullTotalPhys;
#	endif
	}
}

#endif
