#ifndef XIETIE_HEADER_MEMORY_BUFFERSIZE
#	define XIETIE_HEADER_MEMORY_BUFFERSIZE

#	include "../macros/SYSTEM_TYPE.hpp"

#	if XIEITE_SYSTEM_TYPE_UNIX
#		include <cstddef>
#		include <unistd.h>

namespace xieite::memory {
	inline constexpr std::size_t bufferSize = ::sysconf(_SC_PAGE_SIZE);
}

#	else
#		error "System not supported"
#	endif

#endif
