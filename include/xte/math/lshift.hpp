#ifndef DETAIL_XTE_HEADER_MATH_LSHIFT
#	define DETAIL_XTE_HEADER_MATH_LSHIFT
#
#	include "../math/abs.hpp"
#	include "../math/as_unsigned.hpp"
#	include "../math/width.hpp"
#	include "../trait/is_int.hpp"

namespace xte {
	inline constexpr auto lshift = []<xte::is_int Int, xte::is_int Count = xte::uz>[[nodiscard]](Int x, Count count = 1) static noexcept -> Int {
		if (xte::abs(count) >= xte::width<Int>) {
			return 0;
		}
		return static_cast<Int>((count < 0) ? (xte::as_unsigned(x) >> -count) : (xte::as_unsigned(x) << count));
	};
}

#endif
