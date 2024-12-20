export module xieite:num_search;

import std;
import :is_arith;
import :is_invoc;
import :is_nothrow_invoc;
import :almost_eq;
import :neg;

export namespace xieite {
	template<xieite::is_arith T, xieite::is_invoc<bool(T)> F>
	[[nodiscard]] constexpr T num_search(F&& cond, T min, T max)
	noexcept(xieite::is_nothrow_invoc<F, bool(T)>) {
		while (true) {
			const T mid = static_cast<T>((min + max) / 2);
			if (xieite::almost_eq(mid, min) || xieite::almost_eq(mid, max)) {
				return mid;
			}
			(std::invoke_r<bool>(cond, mid) ? max : min) = mid;
		}
	}

	template<xieite::is_arith T, xieite::is_invoc<bool(T)> F>
	[[nodiscard]] constexpr T num_search(F&& cond)
	noexcept(xieite::is_nothrow_invoc<F, bool(T)>) {
		if constexpr (!std::unsigned_integral<T>) {
			if (std::invoke_r<bool>(cond, static_cast<T>(0))) {
				T min = -1;
				while (std::invoke_r<bool>(cond, min)) {
					min *= 2;
				}
				return xieite::num_search(cond, min, 0);
			}
		}
		T max = 1;
		while (!std::invoke_r<bool>(cond, max)) {
			max *= 2;
		}
		return xieite::num_search(cond, static_cast<T>(0), max);
	}
}
