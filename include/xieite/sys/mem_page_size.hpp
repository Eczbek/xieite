#pragma once

#include <cstddef>
#include <memory>
#include "../pp/pltf.hpp"

#if XIEITE_PLTF_TYPE_UNIX
#	include <unistd.h>
#elif XIEITE_PLTF_TYPE_WINDOWS
#	include <windows.h>
#else
#	warning "unsupported platform"
#endif

namespace xieite {
	[[nodiscard]] inline std::size_t mem_page_size() noexcept {
#if XIEITE_PLTF_TYPE_UNIX
		return static_cast<std::size_t>(::sysconf(_SC_PAGE_SIZE));
#elif XIEITE_PLTF_TYPE_WINDOWS
		::SYSTEM_INFO info;
		::GetSystemInfo(std::addressof(info));
		return info.dwPageSize;
#endif
	}
}
