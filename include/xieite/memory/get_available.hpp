#ifndef XIEITE_HEADER_MEMORY_GET_AVAILABLE
#	define XIEITE_HEADER_MEMORY_GET_AVAILABLE

#	include "../macros/platform.hpp"

#	if XIEITE_PLATFORM_TYPE_UNIX
#		include <cstddef>
#		include <unistd.h>
#		include "../memory/get_page_size.hpp"

namespace xieite::memory {
	[[nodiscard]] inline std::size_t getAvailable() noexcept {
		return static_cast<std::size_t>(::sysconf(_SC_AVPHYS_PAGES)) * xieite::memory::getPageSize();
	}
}

#	elif XIEITE_PLATFORM_TYPE_WINDOWS
#		include <cstddef>
#		include <windows.h>

namespace xieite::memory {
	[[nodiscard]] inline std::size_t getAvailable() noexcept {
		MEMORYSTATUSEX status;
		status.dwLength = sizeof(status);
		::GlobalMemoryStatusEx(&status);
		return status.ullAvailPhys;
	}
}

#	else
#		error "Platform not supported"
#	endif
#endif
