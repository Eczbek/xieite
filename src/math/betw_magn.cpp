export module xieite:betw_magn;

import std;
import :is_arith;
import :limits_magn;

export namespace xieite {
	template<xieite::is_arith T>
	[[nodiscard]] constexpr bool betw_magn(T value, std::type_identity_t<T> limit0, std::type_identity_t<T> limit1, bool down_incl = true, bool up_incl = true) noexcept {
		const auto [down, up] = xieite::limits_magn(limit0, limit1);
		return (down_incl ? (value >= down) : (value > down))
			&& (up_incl ? (value <= up) : (value < up));
	}
}
