#ifndef DETAIL_XTE_HEADER_MATH_BIT_CEIL
#	define DETAIL_XTE_HEADER_MATH_BIT_CEIL
#
#	include "../math/is_single_bit.hpp"
#	include "../math/leading_zeros.hpp"
#	include "../math/lshift.hpp"
#	include "../trait/is_int.hpp"

namespace xte {
	inline constexpr auto bit_ceil = []<xte::is_int Int>[[nodiscard]](Int x) static noexcept -> Int {
		if (xte::is_single_bit(x |= !x)) {
			return x;
		}
		return xte::lshift(static_cast<Int>(1), xte::width<Int> - xte::leading_zeros(x));
	};
}

#endif
