#ifndef DETAIL_XTE_HEADER_MATH_DIGITS
#	define DETAIL_XTE_HEADER_MATH_DIGITS
#
#	include "../abs.hpp"
#	include "../aliases.hpp"
#	include "../trait/is_int.hpp"
#	include "../trait/is_signed_int.hpp"

namespace xte {
	[[nodiscard]] constexpr xte::uz digits(xte::is_int auto value, decltype(value) radix = 10) noexcept {
		if (!value || !radix) {
			return 1;
		}
		if (radix == 1) {
			return static_cast<xte::uz>(xte::abs(value));
		}
		if constexpr (xte::is_signed_int<decltype(value)>) {
			if (radix == -1) {
				return static_cast<xte::uz>(xte::abs(value) * 2 + 1);
			}
		}
		xte::uz count = 0;
		do {
			++count;
		} while ((value = value / radix + (value < 0)));
		return count;
	}
}

#endif
