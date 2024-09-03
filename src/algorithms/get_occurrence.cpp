export module xieite:algorithms.getOccurrence;

import std;
import :concepts.Invocable;
import :concepts.NoThrowInvocable;
import :concepts.NoThrowOperableRange;

export namespace xieite::algorithms {
	template<std::ranges::forward_range Range, xieite::concepts::Invocable<bool(std::ranges::range_reference_t<Range>)> Functor>
	requires(std::ranges::sized_range<Range>)
	[[nodiscard]] constexpr std::ranges::iterator_t<Range> getOccurrence(Range& range, std::size_t count, Functor&& selector = Functor())
	noexcept(xieite::concepts::NoThrowInvocable<Functor, bool(std::ranges::range_reference_t<Range>)> && xieite::concepts::NoThrowOperableRange<Range>) {
		const auto end = std::ranges::end(range);
		for (auto iterator = std::ranges::begin(range); iterator != end; ++iterator) {
			if (std::invoke_r<bool>(selector, *iterator) && !count--) {
				return iterator;
			}
		}
		return end;
	}
}
