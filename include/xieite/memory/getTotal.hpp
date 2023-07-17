#ifndef XIEITE_HEADER_MEMORY_GETTOTAL
#	define XIEITE_HEADER_MEMORY_GETTOTAL

#	include <xieite/macros/SYSTEM_TYPE.hpp>

#	if XIEITE_SYSTEM_TYPE_UNIX
#		include <cstddef>
#		include <unistd.h>

namespace xieite::memory {
	[[nodiscard]]
	inline std::size_t getTotal() noexcept {
		return static_cast<std::size_t>(sysconf(_SC_PHYS_PAGES)) * static_cast<std::size_t>(sysconf(_SC_PAGE_SIZE));
	}
}

#	else
#		error "System not supported"
#	endif

#endif
