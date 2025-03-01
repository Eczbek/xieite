#pragma once

#include <concepts>
#include "../math/closest.hpp"
#include "../math/farthest.hpp"
#include "../math/intv.hpp"
#include "../trait/isarith.hpp"

namespace x4 {
	template<x4::isarith T, std::convertible_to<T>... Ts>
	[[nodiscard]] constexpr x4::intv<T> minmaxmagn(T first, Ts... rest) noexcept {
		auto result = x4::intv<T>(first, first);
		(..., (result =
			x4::intv<T>(
				x4::closest(static_cast<T>(0), result.start, static_cast<T>(rest)),
				x4::farthest(static_cast<T>(0), result.end, static_cast<T>(rest))
			)
		));
		return result;
	}
}
