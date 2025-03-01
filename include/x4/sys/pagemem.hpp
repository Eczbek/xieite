#pragma once

#include <cstddef>
#include <memory>
#include "../pp/pltf.hpp"

#if X4PLTF_UNIX
#	include <unistd.h>
#elif X4PLTF_WINDOWS
#	include <windows.h>
#else
#	warning "unsupported platform"
#endif

namespace x4 {
	[[nodiscard]] inline std::size_t pagemem() noexcept {
#if X4PLTF_UNIX
		return static_cast<std::size_t>(::sysconf(_SC_PAGE_SIZE));
#elif X4PLTF_WINDOWS
		::SYSTEM_INFO info;
		::GetSystemInfo(std::addressof(info));
		return info.dwPageSize;
#endif
	}
}
