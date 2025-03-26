#ifndef DETAIL_XIEITE_HEADER_MATH_DIFF
#	define DETAIL_XIEITE_HEADER_MATH_DIFF
#
#	include <cmath>
#	include "../trait/is_arith.hpp"
#	include "../trait/try_unsign.hpp"

namespace xieite {
	template<xieite::is_arith T>
	[[nodiscard]] constexpr xieite::try_unsign<T> diff(T n, T m) noexcept {
		if constexpr (std::floating_point<T>) {
			return std::abs(n - m);
		} else {
			using Result = xieite::try_unsign<T>;
			return (n > m)
				? (static_cast<Result>(n) - static_cast<Result>(m))
				: (static_cast<Result>(m) - static_cast<Result>(n));
		}
	}
}

#endif
