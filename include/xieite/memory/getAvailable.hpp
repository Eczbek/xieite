#ifndef XIEITE_HEADER__MEMORY__GET_AVAILABLE
#	define XIEITE_HEADER__MEMORY__GET_AVAILABLE

#	include "../macros/SYSTEM_TYPE.hpp"

#	if XIEITE__SYSTEM_TYPE__UNIX
#		include <cstddef>
#		include <unistd.h>
#		include "../memory/getPageSize.hpp"

namespace xieite::memory {
	inline std::size_t getAvailable() noexcept {
		return (static_cast<std::size_t>(::sysconf(_SC_AVPHYS_PAGES)) * xieite::memory::getPageSize());
	}
}

#	elif XIEITE__SYSTEM_TYPE__WINDOWS
#		include <cstddef>
#		include <windows.h>

namespace xieite::memory {
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
