module;

#include <xieite/pltf.hpp>

#if XIEITE_PLTF_TYPE_UNIX
#	include <unistd.h>
#elif XIEITE_PLTF_TYPE_WINDOWS
#	include <windows.h>
#else
#	warning "unsupported platform"
#endif

export module xieite:mem_page_size;

import std;

export namespace xieite {
	[[nodiscard]] std::size_t mem_page_size() noexcept {
#if XIEITE_PLTF_TYPE_UNIX
		return static_cast<std::size_t>(::sysconf(_SC_PAGE_SIZE));
#elif XIEITE_PLTF_TYPE_WINDOWS
		::SYSTEM_INFO info;
		::GetSystemInfo(std::addressof(info));
		return info.dwPageSize;
#endif
	}
}
