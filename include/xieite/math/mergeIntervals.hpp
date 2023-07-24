#ifndef XIEITE_HEADER_MATH_MERGEINTERVALS
#	define XIEITE_HEADER_MATH_MERGEINTERVALS

#	include <cmath>
#	include <vector>
#	include <xieite/concepts/Arithmetic.hpp>
#	include <xieite/concepts/RangeOf.hpp>
#	include <xieite/math/Interval.hpp>

namespace xieite::math {
	template<xieite::concepts::Arithmetic Arithmetic, xieite::concepts::RangeOf<xieite::math::Interval<Arithmetic>> IntervalRange>
	[[nodiscard]]
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
