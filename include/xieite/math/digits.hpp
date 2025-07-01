#ifndef DETAIL_XIEITE_HEADER_MATH_DIGITS
#	define DETAIL_XIEITE_HEADER_MATH_DIGITS
#
#	include <cmath>
#	include <concepts>
#	include <cstddef>
#	include "../math/abs.hpp"
#	include "../math/almost_equal.hpp"

namespace xieite {
	template<std::integral Int>
	[[nodiscard]] constexpr std::size_t digits(Int x, Int radix = 10) noexcept {
		if (!x || !radix) {
			return 1;
		}
		if (radix == 1) {
			return static_cast<std::size_t>(xieite::abs(x));
		}
		if constexpr (std::signed_integral<Int>) {
			if (radix == -1) {
				return static_cast<std::size_t>(xieite::abs(x) * 2) + 1;
			}
		}
		std::size_t result = 1;
		while (x) {
			if constexpr (std::unsigned_integral<Int>) {
				x /= radix;
			} else {
				x = x / radix + (x < 0);
			}
			++result;
		}
		return result;
	}

	template<std::floating_point Float>
	[[nodiscard]] constexpr std::size_t digits(Float x, Float radix = 10) noexcept {
		x = std::abs(x);
		if ((x - std::abs(radix) < 1) || xieite::almost_equal(radix, static_cast<Float>(0))) {
			return 1;
		}
		if (xieite::almost_equal(radix, static_cast<Float>(1))) {
			return static_cast<std::size_t>(x);
		}
		if (xieite::almost_equal(radix, static_cast<Float>(-1))) {
			return static_cast<std::size_t>(x) * 2 + 1;
		}
		std::size_t result = 1;
		while (x >= radix) {
			x /= radix;
			++result;
		}
		return result;
	}
}

#endif
