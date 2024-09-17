export module xieite:math.isBetweenFixed;

import std;
import :concepts.Arithmetic;

export namespace xieite::math {
	template<xieite::concepts::Arithmetic Arithmetic>
	[[nodiscard]] constexpr bool isBetweenFixed(const Arithmetic value, const std::common_type_t<Arithmetic> limit1, const std::common_type_t<Arithmetic> limit2, const bool floorInclusive = true, const bool ceilingInclusive = true) noexcept {
		return (floorInclusive ? (value >= limit1) : (value > limit1)) && (ceilingInclusive ? (value <= limit2) : (value < limit2)) || (floorInclusive ? (value >= limit2) : (value > limit2)) && (ceilingInclusive ? (value <= limit1) : (value < limit1));
	}
}
