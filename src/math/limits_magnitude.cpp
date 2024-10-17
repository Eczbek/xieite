export module xieite:math.limitsMagnitude;

import std;
import :concepts.Arithmetic;
import :math.closestTo;
import :math.farthestFrom;
import :math.Interval;

export namespace xieite::math {
	template<xieite::concepts::Arithmetic First, std::convertible_to<First>... Rest>
	[[nodiscard]] constexpr xieite::math::Interval<First> limitsMagnitude(const First first, const Rest... rest) noexcept {
		auto result = xieite::math::Interval<First>(first, first);
		(..., (result =
			xieite::math::Interval<First>(
				xieite::math::closestTo(static_cast<First>(0), result.start, static_cast<First>(rest)),
				xieite::math::farthestFrom(static_cast<First>(0), result.end, static_cast<First>(rest))
			)
		));
		return result;
	}
}
