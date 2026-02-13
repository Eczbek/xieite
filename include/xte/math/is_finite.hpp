#ifndef DETAIL_XTE_HEADER_MATH_IS_FINITE
#	define DETAIL_XTE_HEADER_MATH_IS_FINITE
#
#	include "../math/is_infinite.hpp"
#	include "../math/is_nan.hpp"
#	include "../trait/is_number.hpp"

namespace xte {
	inline constexpr auto is_finite = [][[nodiscard]](xte::is_number auto x) static noexcept {
		return !xte::is_infinite(x) && !xte::is_nan(x);
	};
}

#endif
