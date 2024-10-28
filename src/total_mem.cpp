module;

#include <xieite/pltf.hpp>

#if XIEITE_PLTF_TYPE_UNIX
#	include <unistd.h>
#elif XIEITE_PLTF_TYPE_WINDOWS
#	include <windows.h>
#else
#	warning "unsupported platform"
#endif

export module xieite:total_mem;

import std;
import :mem_page_size;

export namespace xieite {
	[[nodiscard]] std::size_t total_mem() noexcept {
#if XIEITE_PLTF_TYPE_UNIX
		return static_cast<std::size_t>(::sysconf(_SC_PHYS_PAGES)) * xieite::mem_page_size();
#elif XIEITE_PLTF_TYPE_WINDOWS
		::MEMORYSTATUSEX status;
		status.dwLength = sizeof(status);
		::GlobalMemoryStatusEx(std::addressof(status));
		return status.ullTotalPhys;
#endif
	}
}
