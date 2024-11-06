export module xieite:add_overflow;

import std;
import :is_arith;
import :neg;

export namespace xieite {
	template<xieite::is_arith T, std::convertible_to<T>... Ts>
	[[nodiscard]] constexpr bool add_overflow(T first, Ts... rest) noexcept {
		return sizeof...(Ts)
			&& first
			&& (... || ([&first, rest] -> bool {
				if (rest && (xieite::neg(first) ? ((std::numeric_limits<T>::min() - first) > rest) : ((std::numeric_limits<T>::max() - first) < rest))) {
					return true;
				}
				first += static_cast<T>(rest);
				return false;
			})());
	}
}
