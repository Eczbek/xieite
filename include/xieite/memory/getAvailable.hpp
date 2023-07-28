#ifndef XIEITE_HEADER_MEMORY_GETAVAILABLE
#	define XIEITE_HEADER_MEMORY_GETAVAILABLE

#	include "../macros/SYSTEM_TYPE.hpp"

#	if XIEITE_SYSTEM_TYPE_UNIX
#		include <cstddef>
#		include <unistd.h>
#		include "../memory/getPageSize.hpp"

namespace xieite::memory {
	[[nodiscard]]
	inline std::size_t getAvailable() noexcept {
		return (static_cast<std::size_t>(::sysconf(_SC_AVPHYS_PAGES)) * xieite::memory::getPageSize());
	}
}

#	elif XIEITE_SYSTEM_TYPE_WINDOWS
#		include <cstddef>
#		include <windows.h>

namespace xieite::memory {
	[[nodiscard]]
	inline std::size_t getAvailable() noexcept {
		::MEMORYSTATUSEX status;
		status.dwLength = sizeof(status);
		::GlobalMemoryStatusEx(&status);
		return status.ullAvailPhys;
	}
}

#	else
#		error "System not supported"
#	endif

#endif
