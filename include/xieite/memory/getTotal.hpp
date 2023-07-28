#ifndef XIEITE_HEADER_MEMORY_GETTOTAL
#	define XIEITE_HEADER_MEMORY_GETTOTAL

#	include "../macros/SYSTEM_TYPE.hpp"

#	if XIEITE_SYSTEM_TYPE_UNIX
#		include <cstddef>
#		include <unistd.h>
#		include "../memory/getPageSize.hpp"

namespace xieite::memory {
	[[nodiscard]]
	inline std::size_t getTotal() noexcept {
		return (static_cast<std::size_t>(::sysconf(_SC_PHYS_PAGES)) * xieite::memory::getPageSize());
	}
}

#	elif XIEITE_SYSTEM_TYPE_WINDOWS
#		include <cstddef>
#		include <windows.h>

namespace xieite::memory {
	[[nodiscard]]
	inline std::size_t getTotal() noexcept {
		::MEMORYSTATUSEX status;
		status.dwLength = sizeof(status);
		::GlobalMemoryStatusEx(&status);
		return status.ullTotalPhys;
	}
}

#	else
#		error "System not supported"
#	endif

#endif
