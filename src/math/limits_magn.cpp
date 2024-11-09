export module xieite:limits_magn;

import std;
import :is_arith;
import :closest;
import :farthest;
import :intv;

export namespace xieite {
	template<xieite::is_arith T, std::convertible_to<T>... Ts>
	[[nodiscard]] constexpr xieite::intv<T> limits_magn(T first, Ts... rest) noexcept {
		auto result = xieite::intv<T>(first, first);
		(..., (result =
			xieite::intv<T>(
				xieite::closest(static_cast<T>(0), result.start, static_cast<T>(rest)),
				xieite::farthest(static_cast<T>(0), result.end, static_cast<T>(rest))
			)
		));
		return result;
	}
}
