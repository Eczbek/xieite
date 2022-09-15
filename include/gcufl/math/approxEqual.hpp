#pragma once

#include <cmath>
#include <gcufl/concepts/Arithmetic.hpp>
#include <limits>


namespace gcufl::math {
	template<gcufl::concepts::Arithmetic N>
	constexpr bool approxEqual(const N value1, const N value2) noexcept {
		return std::fabs(value1 - value2) <= std::numeric_limits<N>::epsilon();
	}
}
