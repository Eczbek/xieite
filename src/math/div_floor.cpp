export module xieite:div_floor;

import std;
import :is_arith;
import :sign;

export namespace xieite {
	template<xieite::is_arith T>
	[[nodiscard]] constexpr T div_floor(T left, T right) noexcept {
		if constexpr (std::floating_point<T>) {
			return std::floor(left / right);
		} else {
			return static_cast<T>(left / right - !!(left % right) * (xieite::sign(left, right) < 0));
		}
	}
}
