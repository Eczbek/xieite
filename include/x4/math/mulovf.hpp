#pragma once

#include <concepts>
#include <limits>
#include "../math/abs.hpp"
#include "../math/neg.hpp"
#include "../trait/isarith.hpp"

namespace x4 {
	template<x4::isarith T, std::convertible_to<T>... Ts>
	[[nodiscard]] constexpr bool mulovf(T first, Ts... rest) noexcept {
		return sizeof...(Ts)
			&& first
			&& (... || ([&first, rest] -> bool {
				if (rest && ((x4::abs((x4::neg(first) != x4::neg(rest)) ? std::numeric_limits<T>::min() : std::numeric_limits<T>::max()) / x4::abs(first)) < x4::abs(rest))) {
					return true;
				}
				first *= static_cast<T>(rest);
				return false;
			})());
	}
}
