export module xieite:merge_intervals;

import std;
import :betw;
import :interval;
import :is_arith;
import :minmax;

export namespace xieite {
	template<xieite::is_arith T, std::ranges::input_range R>
	requires(std::convertible_to<std::ranges::range_value_t<R>, xieite::interval<T>>)
	[[nodiscard]] constexpr std::vector<xieite::interval<T>> merge_intervals(R&& intervals) noexcept {
		std::vector<xieite::interval<T>> result;
		for (xieite::interval<T> interval0 : intervals) {
			const xieite::interval<T> ordered = xieite::minmax(interval0.start, interval0.end);
			const auto [lower, upper] = ordered;
			bool overlaps = false;
			for (xieite::interval<T>& interval1 : result) {
				const auto [start, end] = interval1;
				if (xieite::betw(lower, start, end) || xieite::betw(upper, start, end)) {
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
