export module xieite:algorithms.partialReverse;

import std;
import :concepts.Invocable;
import :concepts.NoThrowInvocable;
import :concepts.NoThrowOperableRange;

export namespace xieite::algorithms {
	template<std::ranges::forward_range Range, xieite::concepts::Invocable<bool(std::ranges::range_common_reference_t<Range>)> Functor>
	requires(std::ranges::sized_range<Range> && !std::is_const_v<std::ranges::iterator_t<Range>>)
	constexpr void partialReverse(Range& range, Functor&& selector)
	noexcept(xieite::concepts::NoThrowInvocable<Functor, bool(std::ranges::range_common_reference_t<Range>)> && xieite::concepts::NoThrowOperableRange<Range>) {
		auto iterator = std::ranges::begin(range);
		const auto end = std::ranges::end(range);
		std::vector<std::ranges::iterator_t<Range>> iterators;
		for (; iterator != end; ++iterator) {
			if (std::invoke(selector, *iterator)) {
				iterators.push_back(iterator);
			}
		}
		const std::size_t iteratorsSize = std::ranges::size(iterators);
		for (std::size_t i = 0; i < (iteratorsSize / 2); ++i) {
			std::ranges::iter_swap(iterators[i], iterators[iteratorsSize - i - 1]);
		}
	}
}
