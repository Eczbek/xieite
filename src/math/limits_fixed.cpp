export module xieite:math.limits;

import std;
import :concepts.Arithmetic;
import :math.Interval;

export namespace xieite::math {
	template<xieite::math::Arithmetic First, std::convertible_to<First>... Rest>
	[[nodiscard]] constexpr xieite::math::Interval<First> limitsFixed(const First first, const Rest... rest) noexcept {
		auto result = xieite::math::Interval<First>(first, first);
		(..., ([] {
			if (rest < result.start) {
				result.start = static_cast<First>(rest);
			} else if (rest > result.end) {
				result.end = static_cast<First>(rest);
			}
		})());
		return result;
	}
}
