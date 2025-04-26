#ifndef DETAIL_XIEITE_HEADER_MATH_BIT_SIZE
#	define DETAIL_XIEITE_HEADER_MATH_BIT_SIZE
#
#	include <concepts>
#	include <cstddef>
#	include <limits>

namespace xieite {
	template<typename T>
	constexpr std::size_t bit_size = sizeof(T) * std::numeric_limits<unsigned char>::digits;

	template<std::integral Int>
	constexpr std::size_t bit_size<Int> = std::numeric_limits<Int>::digits + std::numeric_limits<Int>::is_signed;
}

#endif

// After a long and very intense debate between FOUR different wizards on several topics of varying relativity, it was deemed that `std::numeric_limits<unsigned char>::digits` and `CHAR_BIT` both are terrible options and there's no good way of doing anything at all
