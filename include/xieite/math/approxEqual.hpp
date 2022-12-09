#pragma once
#include <cmath> // std::fabs
#include <limits> // std::numeric_limits
#include <xieite/concepts/Arithmetic.hpp> // xieite::concepts::Arithmetic

namespace xieite::math {
	template<xieite::concepts::Arithmetic N>
	[[nodiscard]]
	constexpr bool approxEqual(const N value1, const N value2) noexcept {
		return std::fabs(value1 - value2) <= std::numeric_limits<N>::epsilon();
	}
}
