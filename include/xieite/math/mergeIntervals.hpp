#ifndef XIEITE_HEADER_MATH_MERGEINTERVALS
#	define XIEITE_HEADER_MATH_MERGEINTERVALS

#	include <cmath>
#	include <vector>
#	include <xieite/concepts/Arithmetic.hpp>
#	include <xieite/concepts/RangeOf.hpp>
#	include <xieite/math/Interval.hpp>

namespace xieite::math {
	template<xieite::concepts::Arithmetic Number>
	[[nodiscard]]
	constexpr std::vector<xieite::math::Interval<Number>> mergeIntervals(const xieite::concepts::RangeOf<xieite::math::Interval<Number>> auto& intervals) noexcept {
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
