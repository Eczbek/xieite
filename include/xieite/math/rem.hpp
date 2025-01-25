#pragma once

#include <cmath>
#include <concepts>
#include "../trait/is_arith.hpp"

namespace xieite {
	template<xieite::is_arith T>
	[[nodiscard]] constexpr T rem(T dividend, T divisor) noexcept {
		if constexpr (std::floating_point<T>) {
			return std::fmod(dividend, divisor);
		} else {
			return dividend % divisor;
		}
	}
}
