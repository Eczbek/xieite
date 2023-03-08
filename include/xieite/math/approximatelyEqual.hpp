#pragma once
#include <cmath> // std::abs
#include <limits> // std::numeric_limits
#include <xieite/concepts/Arithmetic.hpp>

namespace xieite::math {
	template<xieite::concepts::Arithmetic N, xieite::concepts::Arithmetic O>
	[[nodiscard]]
	constexpr bool approximatelyEqual(const N value1, const O value2) noexcept {
		return (std::abs(value1 - static_cast<N>(value2)) <= std::numeric_limits<N>::epsilon()) && (std::abs(static_cast<O>(value1) - value2) <= std::numeric_limits<O>::epsilon());
	}
}
