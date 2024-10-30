export module xieite:merge_intervals;

import std;
import :is_arith;
import :between_fixed;
import :limits_fixed;
import :interval;

export namespace xieite {
	template<xieite::is_arith T, std::ranges::input_range R>
	requires(std::convertible_to<std::ranges::range_value_t<R>, xieite::interval<T>>)
	[[nodiscard]] constexpr std::vector<xieite::interval<T>> merge_intervals(R&& intervals) noexcept {
		std::vector<xieite::interval<T>> result;
		for (xieite::interval<T> interval1 : intervals) {
			const xieite::interval<T> ordered = xieite::limits_fixed(interval1.start, interval1.end);
			const auto [lower, upper] = ordered;
			bool overlaps = false;
			for (xieite::interval<T>& interval2 : result) {
				const auto [start, end] = interval2;
				if (xieite::between_fixed(lower, start, end) || xieite::between_fixed(upper, start, end)) {
					overlaps = true;
					interval2 = xieite::limits_fixed(lower, upper, start, end);
				}
			}
			if (!overlaps) {
				result.push_back(ordered);
			}
		}
		return result;
	}
}
