#pragma once

#include <cmath>
#include <concepts>
#include <limits>
#include "../trait/isarith.hpp"

namespace x4 {
	template<x4::isarith T, std::convertible_to<T>... Ts>
	[[nodiscard]] constexpr bool expovf(T first, Ts... rest) noexcept {
		return sizeof...(Ts)
			&& first
			&& (first != 1)
			&& (std::unsigned_integral<T> || (first != static_cast<T>(-1)))
			&& (... || ([&first, rest] -> bool {
				const auto pow = std::pow(first, rest);
				if ((pow > std::numeric_limits<T>::max()) || (!std::unsigned_integral<T> && (pow < std::numeric_limits<T>::min()))) {
					return true;
				}
				first = static_cast<T>(pow);
				return false;
			})());
	}
}
