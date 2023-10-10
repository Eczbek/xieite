#pragma once

#include <cmath>
#include "../concepts/arithmetic.hpp"
#include "../math/result.hpp"

namespace xieite::math {
	template<xieite::concepts::Arithmetic Arithmetic1, xieite::concepts::Arithmetic Arithmetic2>
	[[nodiscard]] constexpr xieite::math::Result<Arithmetic1, Arithmetic2> logarithm(const Arithmetic1 base, const Arithmetic2 value) noexcept {
		return std::log(value) / std::log(base); // I found std::log to be slightly faster than std::log2 and std::log10
	}
}
