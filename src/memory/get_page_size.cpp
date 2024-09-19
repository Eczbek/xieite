module;

#include <xieite/platform.hpp>

#if XIEITE_PLATFORM_TYPE_UNIX
#	include <unistd.h>
#elif XIEITE_PLATFORM_TYPE_WINDOWS
#	include <windows.h>
#else
#	warning "unsupported platform"
#endif

export module xieite:memory.getPageSize;

import std;

export namespace xieite::memory {
	[[nodiscard]] std::size_t getPageSize() noexcept {
#if XIEITE_PLATFORM_TYPE_UNIX
		return static_cast<std::size_t>(::sysconf(_SC_PAGE_SIZE));
#elif XIEITE_PLATFORM_TYPE_WINDOWS
		::SYSTEM_INFO info;
		::GetSystemInfo(std::addressof(info));
		return info.dwPageSize;
#endif
	}
}
