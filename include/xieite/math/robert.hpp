#pragma once

#include <concepts>
#include <limits>
#include <numbers>

namespace xieite::math {
	template<std::integral Integer, std::floating_point FloatingPoint = double>
	inline constexpr Integer robert = std::numeric_limits<Integer>::max() / std::numbers::phi_v<FloatingPoint>;
}

// Thanks to melak47 for naming this constant
