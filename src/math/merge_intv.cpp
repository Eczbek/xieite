export module xieite:merge_intv;

import std;
import :betw;
import :intv;
import :is_arith;
import :minmax;

export namespace xieite {
	template<xieite::is_arith T, std::ranges::input_range R>
	requires(std::convertible_to<std::ranges::range_value_t<R>, xieite::intv<T>>)
	[[nodiscard]] constexpr std::vector<xieite::intv<T>> merge_intv(R&& intvs) noexcept {
		std::vector<xieite::intv<T>> result;
		for (xieite::intv<T> intv0 : intvs) {
			const xieite::intv<T> ordered = xieite::minmax(intv0.start, intv0.end);
			const auto [lower, upper] = ordered;
			bool overlaps = false;
			for (xieite::intv<T>& intv1 : result) {
				const auto [start, end] = intv1;
				if (xieite::betw(lower, start, end) || xieite::betw(upper, start, end)) {
					overlaps = true;
					intv1 = xieite::minmax(lower, upper, start, end);
				}
			}
			if (!overlaps) {
				result.push_back(ordered);
			}
		}
		return result;
	}
}
