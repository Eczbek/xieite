#ifndef DETAIL_XIEITE_HEADER_MATH_MERGE_INTERVALS
#	define DETAIL_XIEITE_HEADER_MATH_MERGE_INTERVALS
#
#	include <concepts>
#	include <ranges>
#	include <vector>
#	include "../math/between.hpp"
#	include "../math/minmax.hpp"
#	include "../math/interval.hpp"
#	include "../trait/is_arith.hpp"

namespace xieite {
	template<xieite::is_arith Arith, std::ranges::input_range Range>
	requires(std::convertible_to<std::ranges::range_value_t<Range>, xieite::interval<Arith>>)
	[[nodiscard]] constexpr std::vector<xieite::interval<Arith>> merge_intervals(Range&& intervals) noexcept {
		std::vector<xieite::interval<Arith>> result;
		for (xieite::interval<Arith> interval0 : intervals) {
			const xieite::interval<Arith> ordered = xieite::minmax(interval0.start, interval0.end);
			const auto [lower, upper] = ordered;
			bool overlaps = false;
			for (xieite::interval<Arith>& interval1 : result) {
				const auto [start, end] = interval1;
				if (xieite::between(lower, start, end) || xieite::between(upper, start, end)) {
					overlaps = true;
					interval1 = xieite::minmax(lower, upper, start, end);
				}
			}
			if (!overlaps) {
				result.push_back(ordered);
			}
		}
		return result;
	}
}

#endif
