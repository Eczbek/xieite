#ifndef XIEITE_HEADER_TYPES_BITS
#	define XIEITE_HEADER_TYPES_BITS

#	include <climits>
#	include <cstddef>

namespace xieite::types {
	template<typename Any>
	inline constexpr std::size_t bits = sizeof(Any) * CHAR_BIT;
}

#endif
