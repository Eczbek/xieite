#pragma once
#include <cmath> // std::cos
#include <xieite/concepts/Arithmetic.hpp>

namespace xieite::math {
	template<xieite::concepts::Arithmetic N>
	[[nodiscard]]
	constexpr N secant(const N value) noexcept {
		return 1.0 / std::cos(value);
	}
}
