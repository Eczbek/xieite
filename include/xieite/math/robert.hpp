#pragma once

#include <concepts>
#include <limits>
#include <numbers>

namespace xieite::math {
	template<std::integral Integral>
	constexpr Integral robert = std::numeric_limits<Integral>::max() / std::numbers::phi_v<long double>;
}

// Thanks to melak47 for naming this constant
