#ifndef XIEITE_HEADER_TYPES_SIZE_BITS
#	define XIEITE_HEADER_TYPES_SIZE_BITS

#	include <cstddef>
#	include "../system/byte_bits.hpp"

namespace xieite::types {
	template<typename Type>
	inline constexpr std::size_t sizeBits = sizeof(Type) * xieite::system::byteBits;
}

#endif
