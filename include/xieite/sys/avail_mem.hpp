#pragma once

#include <cstddef>
#include <memory>
#include "../pp/platform.hpp"
#include "../sys/page_mem.hpp"

#if XIEITE_PLATFORM_TYPE_UNIX
#	include <unistd.h>
#elif XIEITE_PLATFORM_TYPE_WINDOWS
#	include <windows.h>
#else
#	warning unsupported platform
#endif

namespace xieite {
	[[nodiscard]] inline std::size_t avail_mem() noexcept {
#if XIEITE_PLATFORM_TYPE_UNIX
		return static_cast<std::size_t>(::sysconf(_SC_AVPHYS_PAGES)) * xieite::page_mem();
#elif XIEITE_PLATFORM_TYPE_WINDOWS
		::MEMORYSTATUSEX status;
		status.dwLength = sizeof(status);
		::GlobalMemoryStatusEx(std::addressof(status));
		return status.ullAvailPhys;
#else
		return 0;
#endif
	}
}
