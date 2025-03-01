#pragma once

#include <algorithm>
#include <concepts>
#include "../math/intv.hpp"
#include "../trait/isarith.hpp"

namespace x4 {
	template<x4::isarith T, std::convertible_to<T>... Ts>
	[[nodiscard]] constexpr x4::intv<T> minmax(T first, Ts... rest) noexcept {
		auto result = x4::intv<T>(first, first);
		(..., (result = x4::intv<T>(std::min(result.start, rest), std::max(result.end, rest))));
		return result;
	}
}
