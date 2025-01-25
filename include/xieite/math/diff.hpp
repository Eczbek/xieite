#pragma once

#include <cmath>
#include "../meta/try_unsign.hpp"
#include "../trait/is_arith.hpp"

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
