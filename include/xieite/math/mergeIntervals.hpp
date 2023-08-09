#ifndef XIEITE_HEADER__MATH__MERGE_INTERVALS
#	define XIEITE_HEADER__MATH__MERGE_INTERVALS

#	include <algorithm>
#	include <vector>
#	include "../concepts/Arithmetic.hpp"
#	include "../concepts/RangeOf.hpp"
#	include "../math/Interval.hpp"

namespace xieite::math {
	template<xieite::concepts::Arithmetic Arithmetic, xieite::concepts::RangeOf<xieite::math::Interval<Arithmetic>> IntervalRange>
	constexpr std::vector<xieite::math::Interval<Arithmetic>> mergeIntervals(const IntervalRange& intervals) noexcept {
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

#endif
