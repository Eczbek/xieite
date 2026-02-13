#ifndef DETAIL_XTE_HEADER_MATH_LEADING_ZEROS
#	define DETAIL_XTE_HEADER_MATH_LEADING_ZEROS
#
#	include "../math/rshift.hpp"
#	include "../math/width.hpp"
#	include "../trait/is_int.hpp"
#	include "../util/types.hpp"

namespace xte {
	inline constexpr auto leading_zeros = []<xte::is_int Int>[[nodiscard]](Int x) static noexcept -> xte::uz {
		xte::uz count = 0;
		for (; x; x = xte::rshift(x)) {
			++count;
		}
		return xte::width<Int> - count;
	};
}

#endif
