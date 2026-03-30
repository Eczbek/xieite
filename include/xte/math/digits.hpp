#ifndef DETAIL_XTE_HEADER_MATH_DIGITS
#	define DETAIL_XTE_HEADER_MATH_DIGITS
#
#	include "../math/abs.hpp"
#	include "../trait/is_int.hpp"
#	include "../trait/is_signed.hpp"
#	include "../util/types.hpp"

namespace xte {
	[[nodiscard]] constexpr xte::uz digits(xte::is_int auto x, decltype(x) radix = 10) noexcept {
		if (!x || !radix) {
			return 1;
		}
		if (radix == 1) {
			return static_cast<xte::uz>(xte::abs(x));
		}
		if constexpr (xte::is_signed<decltype(x)>) {
			if (radix == -1) {
				return static_cast<xte::uz>(xte::abs(x) * 2 + 1);
			}
		}
		xte::uz count = 0;
		do {
			++count;
		} while ((x = x / radix + (x < 0)));
		return count;
	}
}

#endif
