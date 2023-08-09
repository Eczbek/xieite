#ifndef XIETIE__HEADER__MEMORY__BUFFER_SIZE
#	define XIETIE__HEADER__MEMORY__BUFFER_SIZE

#	include "../memory/getPageSize.hpp"

namespace xieite::memory {
	inline const std::size_t bufferSize = xieite::memory::getPageSize();
}

#endif
