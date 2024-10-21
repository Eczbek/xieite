module;

#include <xieite/arrow.hpp>

export module xieite:algorithms.findMostConsecutive;

import std;
import :algorithms.getMostConsecutive;
import :concepts.Invocable;

export namespace xieite::algorithms {
	template<std::ranges::forward_range Range, xieite::concepts::Invocable<bool(std::ranges::range_common_reference_t<Range>, std::ranges::range_common_reference_t<Range>)> Functor = std::ranges::equal_to>
	requires(std::ranges::sized_range<Range>)
	[[nodiscard]] constexpr auto findMostConsecutive(Range& range, const std::ranges::range_common_reference_t<Range> value, Functor&& comparator = Functor())
	XIEITE_ARROW(xieite::algorithms::getMostConsecutive(range, [&value, &comparator](const std::ranges::range_common_reference_t<Range> other) XIEITE_ARROW(std::invoke_r<bool>(comparator, value, other))))
}
