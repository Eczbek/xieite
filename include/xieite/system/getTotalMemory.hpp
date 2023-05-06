#pragma once

#include <cstddef>
#include <unistd.h>

namespace xieite::system {
	[[nodiscard]]
	std::size_t getTotalMemory() noexcept {
		return static_cast<std::size_t>(sysconf(_SC_PHYS_PAGES)) * static_cast<std::size_t>(sysconf(_SC_PAGE_SIZE));
	}
}
