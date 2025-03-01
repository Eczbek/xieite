#pragma once

#include <cstddef>
#include <memory>
#include "../pp/pltf.hpp"
#include "../sys/pagemem.hpp"

#if X4PLTF_UNIX
#	include <unistd.h>
#elif X4PLTF_WINDOWS
#	include <windows.h>
#else
#	warning "unsupported platform"
#endif

namespace x4 {
	[[nodiscard]] inline std::size_t totalmem() noexcept {
#if X4PLTF_UNIX
		return static_cast<std::size_t>(::sysconf(_SC_PHYS_PAGES)) * x4::pagemem();
#elif X4PLTF_WINDOWS
		::MEMORYSTATUSEX status;
		status.dwLength = sizeof(status);
		::GlobalMemoryStatusEx(std::addressof(status));
		return status.ullTotalPhys;
#endif
	}
}
