#pragma once

#include "../math/neg.hpp"
#include "../pp/fn.hpp"
#include "../trait/isarith.hpp"

namespace x4 {
	template<x4::isarith T, x4::isarith... Ts>
	[[nodiscard]] constexpr int sgn(T first, Ts... rest) noexcept {
		static constexpr auto get = X4FN(($0 > 0) - x4::neg($0));
		return (get(first) * ... * get(rest));
	}
}
