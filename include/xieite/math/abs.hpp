#ifndef DETAIL_XIEITE_HEADER_MATH_ABS
#	define DETAIL_XIEITE_HEADER_MATH_ABS
#
#	include <cmath>
#	include <concepts>
#	include "../trait/is_arith.hpp"
#	include "../trait/try_unsign.hpp"

namespace xieite {
	template<xieite::is_arith T>
	[[nodiscard]] constexpr xieite::try_unsign<T> abs(T n) noexcept {
		if constexpr (std::floating_point<T>) {
			return std::abs(n);
		} else if constexpr (std::unsigned_integral<T>) {
			return n;
		} else {
			return (n < 0)
				? -static_cast<xieite::try_unsign<T>>(n)
				: static_cast<xieite::try_unsign<T>>(n);
		}
	}
}

#endif

// Making the return type `auto` allows the negated value to promote
