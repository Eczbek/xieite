export module xieite:math.mergeIntervals;

import std;
import :concepts.Arithmetic;
import :math.Interval;

export namespace xieite::math {
	template<xieite::concepts::Arithmetic Arithmetic, std::ranges::input_range IntervalRange>
	requires(std::convertible_to<std::ranges::range_value_t<IntervalRange>, xieite::math::Interval<Arithmetic>>)
	[[nodiscard]] constexpr std::vector<xieite::math::Interval<Arithmetic>> mergeIntervals(IntervalRange&& intervals) noexcept {
		std::vector<xieite::math::Interval<Arithmetic>> result;
		for (const xieite::math::Interval<Arithmetic> interval1 : intervals) {
			const Arithmetic min = std::min(interval1.start, interval1.end);
			const Arithmetic max = std::max(interval1.start, interval1.end);
			bool overlaps = false;
			for (xieite::math::Interval<Arithmetic>& interval2 : result) {
				if (((min >= interval2.start) && (min <= interval2.end)) || ((max >= interval2.start) && (max <= interval2.end))) {
					overlaps = true;
					interval2.start = std::min(interval2.start, min);
					interval2.end = std::max(interval2.end, max);
				}
			}
			if (!overlaps) {
				result.push_back(xieite::math::Interval<Arithmetic>(min, max));
			}
		}
		return result;
	}
}
