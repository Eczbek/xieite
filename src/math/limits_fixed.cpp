export module xieite:math.limitsFixed;

import std;
import :concepts.Arithmetic;
import :math.Interval;

export namespace xieite::math {
	template<xieite::concepts::Arithmetic First, std::convertible_to<First>... Rest>
	[[nodiscard]] constexpr xieite::math::Interval<First> limitsFixed(const First first, const Rest... rest) noexcept {
		auto result = xieite::math::Interval<First>(first, first);
		(..., (result = xieite::math::Interval<First>(std::min(result.start, rest), std::max(result.end, rest))));
		return result;
	}
}
