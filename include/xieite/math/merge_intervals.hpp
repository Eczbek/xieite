#ifndef XIEITE_HEADER_MATH_MERGE_INTERVALS
#	define XIEITE_HEADER_MATH_MERGE_INTERVALS

#	include <algorithm>
#	include <vector>
#	include "../concepts/arithmetic.hpp"
#	include "../concepts/range_of.hpp"
#	include "../math/interval.hpp"

namespace xieite::math {
	template<xieite::concepts::Arithmetic Arithmetic_, xieite::concepts::RangeOf<xieite::math::Interval<Arithmetic_>> IntervalRange_>
	[[nodiscard]] constexpr std::vector<xieite::math::Interval<Arithmetic_>> mergeIntervals(IntervalRange_&& intervals) noexcept {
		std::vector<xieite::math::Interval<Arithmetic_>> result;
		for (const xieite::math::Interval<Arithmetic_> interval1 : intervals) {
			const Arithmetic_ min = std::min(interval1.start, interval1.end);
			const Arithmetic_ max = std::max(interval1.start, interval1.end);
			bool overlaps = false;
			for (xieite::math::Interval<Arithmetic_>& interval2 : result) {
				if (((min >= interval2.start) && (min <= interval2.end)) || ((max >= interval2.start) && (max <= interval2.end))) {
					overlaps = true;
					interval2.start = std::min(interval2.start, min);
					interval2.end = std::max(interval2.end, max);
				}
			}
			if (!overlaps) {
				result.push_back(xieite::math::Interval<Arithmetic_>(min, max));
			}
		}
		return result;
	}
}

#endif
