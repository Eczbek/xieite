#pragma once

#include <cmath>
#include <gcufl/concepts/Arithmetic.hpp>


namespace gcufl::math {
	template<gcufl::concepts::Arithmetic N>
	constexpr N wrap(const N value, const N max, const N min = 0) noexcept {
		const N diff = max - min;
		return std::fmod(std::fmod(value - min, diff) + diff, diff) + min;
	}
}
