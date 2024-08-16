#ifndef XIEITE_HEADER_BITS_SIZE
#	define XIEITE_HEADER_BITS_SIZE

#	include <climits>
#	include <concepts>
#	include <cstddef>
#	include <limits>

namespace xieite::bits {
	template<typename Type>
	inline constexpr std::size_t size = sizeof(Type) * CHAR_BIT;

	template<std::integral Integral>
	inline constexpr std::size_t size<Integral> = std::numeric_limits<Integral>::digits + std::numeric_limits<Integral>::is_signed;
}

#endif

// After a long and very intense debate between FOUR different wizards on several topics of varying relativity, it was deemed that `std::numeric_limits<unsigned char>::digits` and `CHAR_BIT` both are terrible options and there's no good way of doing anything at all
