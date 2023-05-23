#ifndef XIEITE_HEADER_SYSTEM_GETTOTALMEMORY
#	define XIEITE_HEADER_SYSTEM_GETTOTALMEMORY

#	include <xieite/macros/SYSTEM_TYPE.hpp>

#	ifdef XIEITE_SYSTEM_TYPE_LINUX
#		include <cstddef>
#		include <unistd.h>

namespace xieite::system {
	[[nodiscard]]
	inline std::size_t getTotalMemory() noexcept {
		return static_cast<std::size_t>(sysconf(_SC_PHYS_PAGES)) * static_cast<std::size_t>(sysconf(_SC_PAGE_SIZE));
	}
}

#	else
#		error "System not supported"
#	endif

#endif
