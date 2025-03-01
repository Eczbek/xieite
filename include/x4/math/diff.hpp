#pragma once

#include <cmath>
#include "../meta/tryunsign.hpp"
#include "../trait/isarith.hpp"

namespace x4 {
	template<x4::isarith T>
	[[nodiscard]] constexpr x4::tryunsign<T> diff(T n, T m) noexcept {
		if constexpr (std::floating_point<T>) {
			return std::abs(n - m);
		} else {
			using Result = x4::tryunsign<T>;
			return (n > m)
				? (static_cast<Result>(n) - static_cast<Result>(m))
				: (static_cast<Result>(m) - static_cast<Result>(n));
		}
	}
}
