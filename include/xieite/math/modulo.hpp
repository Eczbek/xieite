#pragma once

#include <cmath>
#include "../concepts/arithmetic.hpp"

namespace xieite::math {
	template<xieite::concepts::Arithmetic Arithmetic>
	[[nodiscard]] constexpr Arithmetic modulo(const Arithmetic dividend, const Arithmetic divisor) noexcept {
		return std::fmod(std::fmod(dividend, divisor) + divisor, divisor);
	}
}
