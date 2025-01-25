#pragma once

#include <cmath>
#include <concepts>
#include "../meta/try_unsign.hpp"
#include "../trait/is_arith.hpp"

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

// NOTE: Making the return type `auto` allows the negated value to promote
