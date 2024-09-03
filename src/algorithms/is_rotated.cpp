export module xieite:algorithms.isRotated;

import std;
import :concepts.Invocable;
import :concepts.NoThrowInvocable;
import :concepts.NoThrowOperableRange;

export namespace xieite::algorithms {
	template<std::ranges::input_range Range1, std::ranges::input_range Range2, xieite::concepts::Invocable<bool(std::ranges::range_reference_t<Range1>, std::ranges::range_reference_t<Range2>)> Functor = std::ranges::equal_to>
	[[nodiscard]] constexpr bool isRotated(Range1&& range1, Range2&& range2, Functor&& comparator = Functor())
	noexcept(xieite::concepts::NoThrowInvocable<Functor, bool(std::ranges::range_reference_t<Range1>, std::ranges::range_reference_t<Range2>)> && xieite::concepts::NoThrowOperableRange<Range1> && xieite::concepts::NoThrowOperableRange<Range2>) {
		const auto begin1 = std::ranges::begin(range1);
		const auto end1 = std::ranges::end(range1);
		const auto begin2 = std::ranges::begin(range2);
		const auto end2 = std::ranges::end(range2);
		if (std::ranges::size(range1) == std::ranges::size(range2)) {
			for (auto iterator = begin1; iterator != end1; ++iterator) {
				auto copy1 = iterator;
				auto copy2 = begin2;
				while (copy2 != end2) {
					if (copy1 == end1) {
						copy1 = begin1;
					}
					if (!std::invoke_r<bool>(comparator, *copy1, *copy2)) {
						break;
					}
					++copy1;
					++copy2;
				}
				if (copy2 == end2) {
					return true;
				}
			}
		}
		return false;
	}
}
