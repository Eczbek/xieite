#pragma once
#include <cmath>
#include <concepts>

namespace gcufl::math {
	template<std::floating_point N>
	constexpr N cot(const N value) noexcept {
		return std::cos(value) / std::sin(value);
	}
}
