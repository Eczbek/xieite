export module xieite:partial_reverse;

import std;
import :is_invoc;
import :is_noex_invoc;
import :is_noex_range;

export namespace xieite {
	template<std::ranges::bidirectional_range R, xieite::is_invoc<bool(std::ranges::range_common_reference_t<R>)> F>
	requires(std::indirectly_swappable<std::ranges::iterator_t<R>>)
	constexpr void partial_reverse(R& range, F&& cond)
	noexcept(xieite::is_noex_invoc<F, bool(std::ranges::range_common_reference_t<R>)> && xieite::is_noex_range<R>) {
		auto first = std::ranges::begin(range);
		auto last = std::ranges::end(range);
		while (true) {
			first = std::ranges::find_if(first, last, cond);
			last = std::ranges::find_last_if(first, last, cond);
			if (first == last) {
				break;
			}
			std::ranges::iter_swap(first, last);
			++first;
			--last;
		}
	}
}
