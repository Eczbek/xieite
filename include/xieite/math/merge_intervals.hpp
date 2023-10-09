#ifndef XIEITE_HEADER__MATH__MERGE_INTERVALS
#	define XIEITE_HEADER__MATH__MERGE_INTERVALS

#	include <algorithm>
#	include <vector>
#	include "../concepts/numeric.hpp"
#	include "../concepts/range_of.hpp"
#	include "../math/interval.hpp"

namespace xieite::math {
	template<xieite::concepts::Numeric Number, xieite::concepts::RangeOf<xieite::math::Interval<Number>> IntervalRange>
	[[nodiscard]] constexpr std::vector<xieite::math::Interval<Number>> mergeIntervals(const IntervalRange& intervals) noexcept {
		std::vector<xieite::math::Interval<Number>> result;
		for (const xieite::math::Interval<Number> interval1 : intervals) {
			const Number min = std::min(interval1.start, interval1.end);
			const Number max = std::max(interval1.start, interval1.end);
			bool overlaps = false;
			for (xieite::math::Interval<Number>& interval2 : result) {
				if (((min >= interval2.start) && (min <= interval2.end)) || ((max >= interval2.start) && (max <= interval2.end))) {
					overlaps = true;
					interval2.start = std::min(interval2.start, min);
					interval2.end = std::max(interval2.end, max);
				}
			}
			if (!overlaps) {
				result.push_back(xieite::math::Interval<Number>(min, max));
			}
		}
		return result;
	}
}

#endif
