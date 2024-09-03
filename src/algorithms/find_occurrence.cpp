export module xieite:algorithms.findOccurrence;

import std;
import :algorithms.getOccurrence;
import :concepts.Invocable;
import :concepts.NoThrowInvocable;
import :concepts.NoThrowOperableRange;

export namespace xieite::algorithms {
	template<std::ranges::forward_range Range, xieite::concepts::Invocable<bool(std::ranges::range_reference_t<Range>, std::ranges::range_reference_t<Range>)> Functor = std::ranges::equal_to>
	requires(std::ranges::sized_range<Range>)
	[[nodiscard]] constexpr std::ranges::iterator_t<Range> findOccurrence(Range& range, std::size_t count, const std::ranges::range_reference_t<Range> value, Functor&& comparator = Functor())
	noexcept(xieite::concepts::NoThrowInvocable<Functor, bool(std::ranges::range_reference_t<Range>, std::ranges::range_reference_t<Range>)> && xieite::concepts::NoThrowOperableRange<Range>) {
		return xieite::algorithms::getOccurrence(range, count, [&value, &comparator](const std::ranges::range_reference_t<Range> other) -> bool {
			return std::invoke_r<bool>(comparator, value, other);
		});
	}
}
