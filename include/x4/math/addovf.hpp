#pragma once

#include <concepts>
#include <limits>
#include "../math/neg.hpp"
#include "../trait/isarith.hpp"

namespace x4 {
	template<x4::isarith T, std::convertible_to<T>... Ts>
	[[nodiscard]] constexpr bool addovf(T first, Ts... rest) noexcept {
		return sizeof...(Ts)
			&& first
			&& (... || ([&first, rest] -> bool {
				if (rest && (x4::neg(first) ? ((std::numeric_limits<T>::min() - first) > rest) : ((std::numeric_limits<T>::max() - first) < rest))) {
					return true;
				}
				first += static_cast<T>(rest);
				return false;
			})());
	}
}
