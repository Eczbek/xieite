#ifndef DETAIL_XTE_HEADER_MATH_SIGN
#	define DETAIL_XTE_HEADER_MATH_SIGN
#
#	include "../math/is_neg.hpp"
#	include "../trait/is_number.hpp"
#	include "../util/numbers.hpp"

namespace xte {
	inline constexpr auto sign = [][[nodiscard]](xte::is_number auto x, xte::is_number auto... ys) static noexcept -> xte::iz {
		return ((!xte::is_neg(x) * 2z - 1z) * ... * (!xte::is_neg(ys) * 2z - 1z));
	};
}

#endif
