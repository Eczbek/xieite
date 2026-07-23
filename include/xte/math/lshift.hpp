#ifndef DETAIL_XTE_HEADER_MATH_LSHIFT
#	define DETAIL_XTE_HEADER_MATH_LSHIFT
#
#	include "../math/abs.hpp"
#	include "../math/as_unsigned.hpp"
#	include "../math/width.hpp"
#	include "../trait/is_int.hpp"

namespace xte {
	inline constexpr auto lshift = []<xte::is_int value_type, xte::is_int count_type = xte::uz>[[nodiscard]](value_type x, count_type count = 1) static noexcept -> value_type {
		if (xte::abs(count) >= xte::width<value_type>) {
			return 0;
		}
		return static_cast<value_type>((0 < count) ? (xte::as_unsigned(x) << count) : (xte::as_unsigned(x) >> -count));
	};
}

#endif
