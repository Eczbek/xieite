#pragma once

#include <concepts>

namespace xieite::math {
	template<std::unsigned_integral UnsignedInteger>
	[[nodiscard]] constexpr bool isPowerOf2(const UnsignedInteger value) noexcept {
		return value && !(value & (value - 1));
	}
}
