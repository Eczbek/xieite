#pragma once

#include <cstddef>
#include <unistd.h>

namespace xieite::system {
	[[nodiscard]]
	inline std::size_t getAvailableMemory() noexcept {
		return static_cast<std::size_t>(sysconf(_SC_AVPHYS_PAGES)) * static_cast<std::size_t>(sysconf(_SC_PAGE_SIZE));
	}
}
