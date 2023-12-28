#ifndef XIETIE_HEADER_MEMORY_GET_PAGE_SIZE
#	define XIETIE_HEADER_MEMORY_GET_PAGE_SIZE

#	include "../macros/platform.hpp"

#	if XIEITE_PLATFORM_UNIX
#		include <cstddef>
#		include <unistd.h>

namespace xieite::memory {
	[[nodiscard]] inline std::size_t getPageSize() noexcept {
		return sysconf(_SC_PAGE_SIZE);
	}
}

#	elif XIEITE_PLATFORM_WINDOWS
#		include <cstddef>
#		include <windows.h>

namespace xieite::memory {
	[[nodiscard]] inline std::size_t getPageSize() noexcept {
		SYSTEM_INFO info;
		GetSystemInfo(&info);
		return info.dwPageSize;
	}
}

#	else
#		error "Platform not supported"
#	endif

#endif
