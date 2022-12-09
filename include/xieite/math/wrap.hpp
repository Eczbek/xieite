#pragma once
#include <cmath> // std::fmod
#include <xieite/concepts/Arithmetic.hpp> // xieite::concepts::Arithmetic

namespace xieite::math {
	template<xieite::concepts::Arithmetic N>
	[[nodiscard]]
	constexpr N wrap(const N value, const N max, const N min = 0) noexcept {
		const N diff = max - min + 1;
		return std::fmod(std::fmod(value - min, diff) + diff, diff) + min;
	}
}
