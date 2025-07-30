#ifndef DETAIL_XIEITE_HEADER_MATH_REVERSE_NUMBER
#	define DETAIL_XIEITE_HEADER_MATH_REVERSE_NUMBER
#
#	include <concepts>
#	include <limits>
#	include <type_traits>
#	include "../math/abs.hpp"
#	include "../math/neg.hpp"

namespace xieite {
	template<std::integral Int>
	[[nodiscard]] constexpr Int reverse_number(Int x, std::type_identity_t<Int> radix = 10) noexcept {
		if (!radix) {
			return 0;
		} else if ((radix == 1) || (!std::unsigned_integral<Int> && (radix == static_cast<Int>(-1)))) {
			return x;
		}
		const bool neg = xieite::neg(x);
		Int result = 0;
		const auto next = [&x, radix, &result](Int digit) -> void {
			x /= radix;
			if (xieite::neg(digit)) {
				digit = xieite::neg(radix) ? (digit - radix) : (digit + radix);
				++x;
			}
			result = result * radix + digit;
		};
		if (x == std::numeric_limits<Int>::min()) {
			next(-(x % radix));
		}
		x = static_cast<Int>(xieite::abs(x));
		while (x) {
			next(x % radix);
		}
		return neg ? -result : result;
	}
}

#endif
