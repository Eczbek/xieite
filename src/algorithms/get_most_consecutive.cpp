export module xieite:algorithms.getMostConsecutive;

import std;
import :concepts.Invocable;
import :concepts.NoThrowInvocable;
import :concepts.NoThrowOperableRange;

export namespace xieite::algorithms {
	template<std::ranges::forward_range Range, xieite::concepts::Invocable<bool(std::ranges::range_reference_t<Range>)> Functor>
	requires(std::ranges::sized_range<Range>)
	[[nodiscard]] constexpr std::ranges::subrange<std::ranges::iterator_t<Range>> getMostConsecutive(Range& range, Functor&& selector = Functor())
	noexcept(xieite::concepts::NoThrowInvocable<Functor, bool(std::ranges::range_reference_t<Range>)> && xieite::concepts::NoThrowOperableRange<Range>) {
		auto iterator = std::ranges::begin(range);
		const auto rangeEnd = std::ranges::end(range);
		auto currentStart = iterator;
		auto currentEnd = iterator;
		auto resultStart = currentStart;
		auto resultEnd = currentEnd;
		bool previous = false;
		for (; iterator != rangeEnd; ++iterator) {
			const bool current = std::invoke_r<bool>(selector, *iterator);
			if (current) {
				if (!previous) {
					currentStart = iterator;
					currentEnd = iterator;
				}
				++currentEnd;
			} else if (previous && (std::ranges::distance(currentStart, currentEnd) > std::ranges::distance(resultStart, resultEnd))) {
				resultStart = currentStart;
				resultEnd = currentEnd;
			}
			previous = current;
		}
		if (previous && (std::ranges::distance(currentStart, currentEnd) > std::ranges::distance(resultStart, resultEnd))) {
			return std::ranges::subrange<std::ranges::iterator_t<Range>>(currentStart, currentEnd);
		}
		return std::ranges::subrange<std::ranges::iterator_t<Range>>(resultStart, resultEnd);
	}
}
