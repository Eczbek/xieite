export module xieite:math.isBetweenMagnitude;

import std;
import :concepts.Arithmetic;
import :math.limitsMagnitude;

export namespace xieite::math {
	template<xieite::concepts::Arithmetic Arithmetic>
	[[nodiscard]] constexpr bool isBetweenMagnitude(const Arithmetic value, const std::type_identity_t<Arithmetic> limit1, const std::type_identity_t<Arithmetic> limit2, const bool downInclusive = true, const bool upInclusive = true) noexcept {
		const auto [down, up] = xieite::math::limitsMagnitude(limit1, limit2);
		return (downInclusive ? (value >= down) : (value > down))
			&& (upInclusive ? (value <= up) : (value < up));
	}
}
