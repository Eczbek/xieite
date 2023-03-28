#pragma once

#include <concepts>

namespace xieite::math {
	template<std::integral Integral>
	[[nodiscard]]
	constexpr Integral xorShift(const Integral value, const int bits) noexcept {
		return value ^ (value >> bits);
	}
}
