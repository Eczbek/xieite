#pragma once
#include <cmath>
#include <xieite/concepts/Arithmetic.hpp>

namespace xieite::math {
	template<xieite::concepts::Arithmetic N>
	[[nodiscard]]
	constexpr N cot(const N value) noexcept {
		return std::cos(value) / std::sin(value);
	}
}
