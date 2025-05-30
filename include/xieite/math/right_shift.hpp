#ifndef DETAIL_XIEITE_HEADER_MATH_RIGHT_SHIFT
#	define DETAIL_XIEITE_HEADER_MATH_RIGHT_SHIFT
#
#	include "../math/bit_size.hpp"

namespace xieite {
	template<std::integral Int>
	[[nodiscard]] constexpr Int right_shift(Int x, std::size_t bits) noexcept {
		if (bits < xieite::bit_size<Int>) {
			return x >> bits;
		}
		return 0;
	}
}

#endif
