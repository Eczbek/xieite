#ifndef DETAIL_XTE_HEADER_MATH_RSHIFT
#	define DETAIL_XTE_HEADER_MATH_RSHIFT
#
#	include "../math/as_unsigned.hpp"
#	include "../math/width.hpp"
#	include "../trait/is_int.hpp"
#	include "../util/types.hpp"

namespace xte {
	inline constexpr auto rshift = []<xte::is_int Int>[[nodiscard]](Int x, xte::uz count = 1) static noexcept -> Int {
		if (count >= xte::width<Int>) {
			return 0;
		}
		return static_cast<Int>(xte::as_unsigned(x) >> count);
	};
}

#endif
