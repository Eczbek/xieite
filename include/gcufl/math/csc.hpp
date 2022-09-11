#pragma once

#include <cmath>
#include <concepts>


namespace gcufl::math {
	template <std::floating_point N>
	constexpr N csc(const N value) noexcept {
		return 1 / std::sin(value);
	}
}
