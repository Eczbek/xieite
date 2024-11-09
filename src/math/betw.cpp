export module xieite:betw;

import std;
import :is_arith;
import :limits;

export namespace xieite {
	template<xieite::is_arith T>
	[[nodiscard]] constexpr bool betw(T value, std::type_identity_t<T> limit0, std::type_identity_t<T> limit1, bool lower_incl = true, bool upper_incl = true) noexcept {
		const auto [lower, upper] = xieite::limits(limit0, limit1);
		return (lower_incl ? (value >= lower) : (value > lower))
			&& (upper_incl ? (value <= upper) : (value < upper));
	}
}
