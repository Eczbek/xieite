#pragma once

#include <concepts>
#include <limits>

namespace xieite::math {
	template<std::integral Integral>
	constexpr Integral alternatingBits = std::numeric_limits<Integral>::max() / 3;
}
