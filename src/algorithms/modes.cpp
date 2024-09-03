export module xieite:algorithms.modes;

import std;
import :concepts.Arithmetic;
import :concepts.Invocable;
import :concepts.NoThrowInvocable;
import :concepts.NoThrowOperableRange;

export namespace xieite::algorithms {
	template<std::ranges::forward_range Range, xieite::concepts::Invocable<bool(std::ranges::range_common_reference_t<Range>, std::ranges::range_common_reference_t<Range>)> Functor = std::ranges::greater>
	requires(std::ranges::sized_range<Range> && xieite::concepts::Arithmetic<std::ranges::range_value_t<Range>>)
	[[nodiscard]] constexpr std::vector<std::ranges::iterator_t<Range>> modes(Range& range, Functor&& comparator = Functor())
	noexcept(xieite::concepts::NoThrowInvocable<Functor, bool(std::ranges::range_common_reference_t<Range>, std::ranges::range_common_reference_t<Range>)> && xieite::concepts::NoThrowOperableRange<Range>) {
		std::vector<std::ranges::iterator_t<Range>> iterators;
		const std::size_t rangeSize = std::ranges::size(range);
		if (rangeSize == 1) {
			iterators.push_back(std::ranges::begin(range));
		}
		if (rangeSize <= 1) {
			return iterators;
		}
		auto previous = std::ranges::begin(range);
		auto iterator = std::ranges::next(previous);
		for (std::size_t i = 1; i < (rangeSize - 1); ++i) {
			if (std::invoke(comparator, *iterator, *previous)) {
				const auto next = std::ranges::next(iterator);
				if (std::invoke(comparator, *iterator, *next)) {
					iterators.push_back(iterator);
				} else if (i == (rangeSize - 2)) {
					iterators.push_back(next);
				}
			} else if (i == 1) {
				iterators.push_back(previous);
			}
			previous = iterator++;
		}
		if (std::ranges::size(range) && !iterators.size()) {
			iterators.push_back(std::ranges::begin(range));
		}
		return iterators;
	}
}
