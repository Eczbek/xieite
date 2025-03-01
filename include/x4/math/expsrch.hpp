#pragma once

#include <concepts>
#include <functional>
#include "../math/almosteq.hpp"
#include "../math/neg.hpp"
#include "../trait/isarith.hpp"
#include "../trait/isinvoc.hpp"
#include "../trait/isnoexinvoc.hpp"

namespace x4 {
	template<x4::isarith T, x4::isinvoc<bool(T)> F>
	[[nodiscard]] constexpr T expsrch(F&& cond, T min, T max)
	noexcept(x4::isnoexinvoc<F, bool(T)>) {
		while (true) {
			const T mid = static_cast<T>((min + max) / 2);
			if (x4::almosteq(mid, min) || x4::almosteq(mid, max)) {
				return mid;
			}
			(std::invoke_r<bool>(cond, mid) ? max : min) = mid;
		}
	}

	template<x4::isarith T, x4::isinvoc<bool(T)> F>
	[[nodiscard]] constexpr T expsrch(F&& cond)
	noexcept(x4::isnoexinvoc<F, bool(T)>) {
		if constexpr (!std::unsigned_integral<T>) {
			if (std::invoke_r<bool>(cond, static_cast<T>(0))) {
				T min = -1;
				while (std::invoke_r<bool>(cond, min)) {
					min *= 2;
				}
				return x4::expsrch(cond, min, 0);
			}
		}
		T max = 1;
		while (!std::invoke_r<bool>(cond, max)) {
			max *= 2;
		}
		return x4::expsrch(cond, static_cast<T>(0), max);
	}
}
