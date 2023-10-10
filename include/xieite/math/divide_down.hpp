#pragma once

#include <concepts>

namespace xieite::math {
	template<std::integral Integer>
	[[nodiscard]] constexpr Integer divideDown(const Integer dividend, const Integer divisor) noexcept {
		return dividend / divisor;
	}
}
