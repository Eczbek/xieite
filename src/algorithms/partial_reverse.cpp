export module xieite:algorithms.partialReverse;

import std;
import :concepts.Invocable;
import :concepts.NoThrowInvocable;
import :concepts.NoThrowOperableRange;

export namespace xieite::algorithms {
	template<std::ranges::bidirectional_range Range, xieite::concepts::Invocable<bool(std::ranges::range_common_reference_t<Range>)> Functor>
	requires(std::indirectly_swappable<std::ranges::iterator_t<Range>>)
	constexpr void partialReverse(Range& range, Functor&& selector)
	noexcept(xieite::concepts::NoThrowInvocable<Functor, bool(std::ranges::range_common_reference_t<Range>)> && xieite::concepts::NoThrowOperableRange<Range>) {
		auto first = std::ranges::begin(range);
		auto last = std::ranges::end(range);
		while (true) {
			first = std::ranges::find_if(first, last, selector);
			last = std::ranges::find_last_if(first, last, selector);
			if (first == last) {
				break;
			}
			std::ranges::iter_swap(first, last);
			std::ranges::advance(first, 1);
			std::ranges::advance(last, -1);
		}
	}
}
