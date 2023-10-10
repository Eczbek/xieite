#pragma once

#include "../macros/platform.hpp"

#if XIEITE_PLATFORM_UNIX
#	include <cstddef>
#	include <unistd.h>
#	include "../memory/get_page_size.hpp"

namespace xieite::memory {
	[[nodiscard]] inline std::size_t getTotal() noexcept {
		return static_cast<std::size_t>(::sysconf(_SC_PHYS_PAGES)) * xieite::memory::getPageSize();
	}
}

#elif XIEITE_PLATFORM_WINDOWS
#	include <cstddef>
#	include <windows.h>

namespace xieite::memory {
	[[nodiscard]] inline std::size_t getTotal() noexcept {
		MEMORYSTATUSEX status;
		status.dwLength = sizeof(status);
		GlobalMemoryStatusEx(&status);
		return status.ullTotalPhys;
	}
}

#else
#	error "System not supported"
#endif
