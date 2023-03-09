#pragma once
#include <cmath> // std::sqrt
#include <limits> // std::numeric_limits
#include <xieite/concepts/Arithmetic.hpp>

namespace xieite::math {
	template<xieite::concepts::Arithmetic N>
	[[nodiscard]]
	constexpr N squareRoot(const N value) noexcept {
		if !consteval {
			return std::sqrt(value);
		}
		if ((value < 0) || (value == std::numeric_limits<N>::infinity()))
			return std::numeric_limits<N>::quiet_NaN();
		N current = value;
		N previous = 0;
		while (current != previous) {
			previous = current;
			current = (value / current + current) / 2;
		}
		return current;
	}
}
