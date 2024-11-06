export module xieite:sub_overflow;

import std;
import :is_arith;
import :neg;

export namespace xieite {
	template<xieite::is_arith T, std::convertible_to<T>... Ts>
	[[nodiscard]] constexpr bool sub_overflow(T first, Ts... rest) noexcept {
		return sizeof...(Ts)
			&& first
			&& (... || ([&first, rest] -> bool {
				if (rest && (xieite::neg(rest) ? ((std::numeric_limits<T>::max() + rest) < first) : ((std::numeric_limits<T>::min() + rest) > first))) {
					return true;
				}
				first -= static_cast<T>(rest);
				return false;
			})());
	}
}
