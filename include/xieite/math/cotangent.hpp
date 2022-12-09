#pragma once
#include <cmath> // std::cos, std::sin
#include <xieite/concepts/Arithmetic.hpp> // xieite::concepts::Arithmetic

namespace xieite::math {
	template<xieite::concepts::Arithmetic N>
	[[nodiscard]]
	constexpr N cotangent(const N value) noexcept {
		return std::cos(value) / std::sin(value);
	}
}
