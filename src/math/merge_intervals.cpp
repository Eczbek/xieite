export module xieite:math.mergeIntervals;

import std;
import :concepts.Arithmetic;
import :math.betweenFixed;
import :math.Interval;

export namespace xieite::math {
	template<xieite::concepts::Arithmetic Arithmetic, std::ranges::input_range IntervalRange>
	requires(std::convertible_to<std::ranges::range_value_t<IntervalRange>, xieite::math::Interval<Arithmetic>>)
	[[nodiscard]] constexpr std::vector<xieite::math::Interval<Arithmetic>> mergeIntervals(IntervalRange&& intervals) noexcept {
		std::vector<xieite::math::Interval<Arithmetic>> result;
		for (const xieite::math::Interval<Arithmetic> interval1 : intervals) {
			const xieite::math::Interval<Arithmetic> ordered = xieite::math::limitsFixed(interval1.start, interval1.end);
			const auto [lower, upper] = ordered;
			bool overlaps = false;
			for (xieite::math::Interval<Arithmetic>& interval2 : result) {
				const auto [start, end] = interval2;
				if (xieite::math::betweenFixed(lower, start, end) || xieite::math::betweenFixed(upper, start, end)) {
					overlaps = true;
					interval2 = xieite::math::limitsFixed(lower, upper, start, end);
				}
			}
			if (!overlaps) {
				result.push_back(ordered);
			}
		}
		return result;
	}
}
