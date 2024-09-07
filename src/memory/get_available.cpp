module;

#include <xieite/platform.hpp>

#if XIEITE_PLATFORM_TYPE_UNIX
#	include <unistd.h>
#elif XIEITE_PlATFORM_TYPE_WINDOWS
#	include <windows.h>
#else
#	warning "Platform not supported"
#endif

export module xieite:memory.getAvailable;

import std;
import :memory.getPageSize;

export namespace xieite::memory {
	[[nodiscard]] inline std::size_t getAvailable() noexcept {
#if XIEITE_PLATFORM_TYPE_UNIX
		return static_cast<std::size_t>(::sysconf(_SC_AVPHYS_PAGES)) * xieite::memory::getPageSize();
#elif XIEITE_PLATFORM_TYPE_WINDOWS
		::MEMORYSTATUSEX status;
		status.dwLength = sizeof(status);
		::GlobalMemoryStatusEx(&status);
		return status.ullAvailPhys;
#endif
	}
}
