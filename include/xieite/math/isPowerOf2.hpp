#pragma once

#include <concepts>

namespace xieite::math {
	constexpr bool isPowerOf2(const std::unsigned_integral auto value) noexcept {
		return value && !(value & (value - 1));
	}
}
