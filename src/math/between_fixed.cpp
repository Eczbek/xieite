export module xieite:between_fixed;

import std;
import :is_arith;
import :limits_fixed;

export namespace xieite {
	template<xieite::is_arith T>
	[[nodiscard]] constexpr bool between_fixed(T value, std::type_identity_t<T> limit0, std::type_identity_t<T> limit1, bool lower_incl = true, bool upper_incl = true) noexcept {
		const auto [lower, upper] = xieite::limits_fixed(limit0, limit1);
		return (lower_incl ? (value >= lower) : (value > lower))
			&& (upper_incl ? (value <= upper) : (value < upper));
	}
}
