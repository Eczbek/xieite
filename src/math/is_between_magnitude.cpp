export module xieite:math.isBetweenMagnitude;

import std;
import :concepts.Arithmetic;
import :math.closestTo;

export namespace xieite::math {
	template<xieite::concepts::Arithmetic Arithmetic>
	[[nodiscard]] constexpr bool isBetweenMagnitude(const Arithmetic value, const std::common_type_t<Arithmetic> limit1, const std::common_type_t<Arithmetic> limit2, const bool downInclusive = true, const bool upInclusive = true) noexcept {
		const Arithmetic down = xieite::math::closestTo(static_cast<Arithmetic>(0), limit1, limit2);
		const Arithmetic up = (down == limit1) ? limit2 : limit1;
		return (downInclusive ? (value >= down) : (value > down)) && (upInclusive ? (value <= up) : (value < up)) || (downInclusive ? (value <= down) : (value < down)) && (upInclusive ? (value >= up) : (value > up));
	}
}
