#pragma once
#include <cmath>
#include <xieite/concepts/Arithmetic.hpp>

namespace xieite::math {
	template<xieite::concepts::Arithmetic N>
	[[nodiscard]]
	constexpr N wrap(const N value, const N max, const N min = 0) noexcept {
		const N diff = max - min;
		return std::fmod(std::fmod(value - min, diff) + diff, diff) + min;
	}
}
