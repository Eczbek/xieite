#ifndef DETAIL_XTE_HEADER_MATH_TRAILING_ZEROS
#	define DETAIL_XTE_HEADER_MATH_TRAILING_ZEROS
#
#	include "../math/rshift.hpp"
#	include "../math/width.hpp"
#	include "../trait/is_int.hpp"
#	include "../util/types.hpp"

namespace xte {
	inline constexpr auto trailing_zeros = [][[nodiscard]](xte::is_int auto x) static noexcept -> xte::uz {
		xte::uz count = 0;
		while (!(x & 1) && (++count < xte::width<decltype(x)>)) {
			x = xte::rshift(x);
		}
		return count;
	};
}

#endif
