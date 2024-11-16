export module xieite:math.div_magnify;

import std;
import :is_arith;
import :sign;

export namespace xieite {
	template<xieite::is_arith T>
	[[nodiscard]] constexpr T div_magnify(T left, T right) noexcept {
		if constexpr (std::floating_point<T>) {
			return std::ceil(left / right) - ((left < 0) != (right < 0));
		} else {
			return static_cast<T>(left / right + !!(left % right) * xieite::sign(left, right));
		}
	}
}
