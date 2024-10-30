export module xieite:wrap;

import std;
import :is_arith;
import :mod;

export namespace xieite {
	template<xieite::is_arith T>
	[[nodiscard]] constexpr T wrap(T value, std::type_identity_t<T> limit1, std::type_identity_t<T> limit2) noexcept {
		const T min = std::min(limit1, limit2);
		return xieite::mod(value - min, std::max(limit1, limit2) - min + 1) + min;
	}
}
