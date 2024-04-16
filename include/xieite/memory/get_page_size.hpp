#ifndef XIEITE_HEADER_MEMORY_GET_PAGE_SIZE
#	define XIEITE_HEADER_MEMORY_GET_PAGE_SIZE

#	include "../macros/platform.hpp"

#	if XIEITE_PLATFORM_TYPE_UNIX
#		include <cstddef>
#		include <unistd.h>
#	elif XIEITE_PLATFORM_TYPE_WINDOWS
#		include <cstddef>
#		include <windows.h>
#	else
#		error "Platform not supported"
#	endif

namespace xieite::memory {
	[[nodiscard]] inline std::size_t getPageSize() noexcept {
#	if XIEITE_PLATFORM_TYPE_UNIX
		return ::sysconf(_SC_PAGE_SIZE);
#	elif XIEITE_PLATFORM_TYPE_WINDOWS
		SYSTEM_INFO info;
		::GetSystemInfo(&info);
		return info.dwPageSize;
#	endif
	}
}

#endif
