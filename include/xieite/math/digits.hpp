#pragma once

#include <cmath>
#include <concepts>
#include <cstddef>
#include "../math/absolute.hpp"
#include "../math/logarithm.hpp"

namespace xieite::math {
	template<std::integral Integer>
	[[nodiscard]] constexpr std::size_t digits(const Integer value, const std::size_t base = 10) noexcept {
		return !base ? 0 : ((base == 1) ? value : static_cast<std::size_t>(std::ceil(xieite::math::logarithm(base, xieite::math::absolute(value) + !value + 1))));
	}
}
