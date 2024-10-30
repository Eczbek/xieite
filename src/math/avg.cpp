export module xieite:avg;

import std;
import :is_arith;

export namespace xieite {
	template<xieite::is_arith T, std::common_with<T>... Ts>
	[[nodiscard]] constexpr T avg(T first, Ts... rest) noexcept {
		using U = std::common_type_t<T, Ts...>;
		static constexpr U size = static_cast<U>(sizeof...(rest) + 1);
		U result = static_cast<U>(first) / size + (... + (static_cast<U>(rest) / size));
		if constexpr (std::integral<U>) {
			result += (static_cast<U>(first) % size + (... + (static_cast<U>(rest) % size))) / size;
		}
		return result;
	}
}
