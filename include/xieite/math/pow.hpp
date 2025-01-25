#pragma once

#include <cmath>
#include <concepts>
#include <stdexcept>
#include "../math/neg.hpp"
#include "../math/split_bool.hpp"
#include "../trait/is_arith.hpp"

namespace xieite {
	template<xieite::is_arith T>
	[[nodiscard]] constexpr T pow(T base, T exp) {
		if constexpr (std::floating_point<T>) {
			return std::pow(base, exp);
		} else {
			if ((base == 1) || (exp == 1)) {
				return base;
			}
			if (!std::unsigned_integral<T> && (base == static_cast<T>(-1))) {
				return base * xieite::split_bool(!!(exp & 1));
			}
			if (!base || !exp) {
				if (xieite::neg(exp)) {
					throw std::out_of_range("must not take power of zero to negative exp");
				}
				return !exp;
			}
			T result = 1;
			while (exp) {
				if (exp & 1) {
					result *= base;
				}
				exp >>= 1;
				base *= base;
			}
			return result;
		}
	}
}
