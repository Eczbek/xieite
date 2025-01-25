#pragma once

#include <cstddef>
#include <memory>
#include "../pp/pltf.hpp"
#include "../sys/mem_page_size.hpp"

#if XIEITE_PLTF_TYPE_UNIX
#	include <unistd.h>
#elif XIEITE_PLTF_TYPE_WINDOWS
#	include <windows.h>
#else
#	warning "unsupported platform"
#endif

namespace xieite {
	[[nodiscard]] inline std::size_t mem_avail() noexcept {
#if XIEITE_PLTF_TYPE_UNIX
		return static_cast<std::size_t>(::sysconf(_SC_AVPHYS_PAGES)) * xieite::mem_page_size();
#elif XIEITE_PLTF_TYPE_WINDOWS
		::MEMORYSTATUSEX status;
		status.dwLength = sizeof(status);
		::GlobalMemoryStatusEx(std::addressof(status));
		return status.ullAvailPhys;
#else
		return 0;
#endif
	}
}
