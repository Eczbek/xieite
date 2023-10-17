#ifndef XIEITE_HEADER_TYPES_SIZE_BITS
#	define XIEITE_HEADER_TYPES_SIZE_BITS

#	include <concepts>
#	include <cstddef>
#	include <limits>
#	include "../system/byte_bits.hpp"

namespace xieite::types {
	template<typename Type>
	inline constexpr std::size_t sizeBits = sizeof(Type) * xieite::system::byteBits;

	template<std::integral Integer>
	inline constexpr std::size_t sizeBits<Integer> = std::numeric_limits<Integer>::digits + std::numeric_limits<Integer>::is_signed;
}

#endif
