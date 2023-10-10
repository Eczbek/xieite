#pragma once

#include <concepts>
#include <limits>

namespace xieite::math {
	template<std::integral Integer>
	inline constexpr Integer alternatingBits = std::numeric_limits<Integer>::max() / 3;
}
