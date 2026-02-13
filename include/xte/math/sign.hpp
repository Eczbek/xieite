#ifndef DETAIL_XTE_HEADER_MATH_SIGN
#	define DETAIL_XTE_HEADER_MATH_SIGN
#
#	include "../math/neg.hpp"
#	include "../trait/is_number.hpp"
#	include "../util/types.hpp"

namespace xte {
	inline constexpr auto sign = [][[nodiscard]](xte::is_number auto x, xte::is_number auto... ys) static noexcept -> xte::iz {
		return ((!xte::neg(x) * 2z - 1z) * ... * (!xte::neg(ys) * 2z - 1z));
	};
}

#endif
