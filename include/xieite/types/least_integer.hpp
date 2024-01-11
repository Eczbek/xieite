#ifndef XIEITE_HEADER_TYPES_LEAST_INTEGER
#	define XIEITE_HEADER_TYPES_LEAST_INTEGER

#	include <cstddef>
#	include <cstdint>
#	include <type_traits>
#	include "../types/size_bits.hpp"

namespace xieite::types {
	template<std::size_t bits>
	using LeastInteger = std::conditional_t<bits <= xieite::types::sizeBits<std::uint_least8_t>, std::uint_least8_t, std::conditional_t<bits <= xieite::types::sizeBits<std::uint_least16_t>, std::uint_least16_t, std::conditional_t<bits <= xieite::types::sizeBits<std::uint_least32_t>, std::uint_least32_t, std::uint_least64_t>>>;
}

#endif
