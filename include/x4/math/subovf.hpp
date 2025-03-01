#pragma once

#include <concepts>
#include <limits>
#include "../math/neg.hpp"
#include "../trait/isarith.hpp"

namespace x4 {
	template<x4::isarith T, std::convertible_to<T>... Ts>
	[[nodiscard]] constexpr bool subovf(T first, Ts... rest) noexcept {
		return sizeof...(Ts)
			&& first
			&& (... || ([&first, rest] -> bool {
				if (rest && (x4::neg(rest) ? ((std::numeric_limits<T>::max() + rest) < first) : ((std::numeric_limits<T>::min() + rest) > first))) {
					return true;
				}
				first -= static_cast<T>(rest);
				return false;
			})());
	}
}
