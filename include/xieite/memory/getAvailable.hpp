#ifndef XIEITE_HEADER_MEMORY_GETAVAILABLE
#	define XIEITE_HEADER_MEMORY_GETAVAILABLE

#	include <xieite/macros/SYSTEM_TYPE.hpp>

#	if XIEITE_SYSTEM_TYPE_UNIX
#		include <cstddef>
#		include <unistd.h>

namespace xieite::memory {
	[[nodiscard]]
	inline std::size_t getAvailable() noexcept {
		return static_cast<std::size_t>(::sysconf(_SC_AVPHYS_PAGES)) * static_cast<std::size_t>(::sysconf(_SC_PAGE_SIZE));
	}
}

#	else
#		error "System not supported"
#	endif

#endif
