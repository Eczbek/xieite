#ifndef XIEITE_HEADER_TYPES_SIZE_BITS
#	define XIEITE_HEADER_TYPES_SIZE_BITS

#	include <concepts>
#	include <cstddef>
#	include <limits>
#	include "../system/byte_bits.hpp"

namespace xieite::types {
	template<typename Type_>
	inline constexpr std::size_t sizeBits = sizeof(Type_) * xieite::system::byteBits;

	template<std::integral Integral_>
	inline constexpr std::size_t sizeBits<Integral_> = std::numeric_limits<Integral_>::digits + std::numeric_limits<Integral_>::is_signed;
}

#endif
