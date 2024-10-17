export module xieite:math.isBetweenFixed;

import std;
import :concepts.Arithmetic;
import :math.limitsFixed;

export namespace xieite::math {
	template<xieite::concepts::Arithmetic Arithmetic>
	[[nodiscard]] constexpr bool isBetweenFixed(const Arithmetic value, const std::type_identity_t<Arithmetic> limit1, const std::type_identity_t<Arithmetic> limit2, const bool lowerInclusive = true, const bool upperInclusive = true) noexcept {
		const auto [lower, upper] = xieite::math::limitsFixed(limit1, limit2);
		return (lowerInclusive ? (value >= lower) : (value > lower))
			&& (upperInclusive ? (value <= upper) : (value < upper));
	}
}
