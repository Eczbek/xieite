#ifndef DETAIL_XIEITE_HEADER_MATH_DIGITS
#	define DETAIL_XIEITE_HEADER_MATH_DIGITS
#
#	include <concepts>
#	include <cstddef>
#	include "../math/abs.hpp"
#	include "../math/neg.hpp"

namespace xieite {
	template<std::integral Int>
	[[nodiscard]] constexpr std::size_t digits(Int x, Int radix = 10) noexcept {
		if (!radix) {
			return 1;
		}
		if (radix == 1) {
			return static_cast<std::size_t>(xieite::abs(x));
		}
		if (std::signed_integral<Int> && (radix == static_cast<Int>(-1))) {
			return static_cast<std::size_t>(xieite::abs(x) * 2) + 1;
		}
		std::size_t result = 0;
		do {
			x = x / radix + xieite::neg(x % radix);
			++result;
		} while (x);
		return result;
	}
}

#endif
