#ifndef XIEITE_HEADER_ALGORITHMS_FIND_MAXIMUM_CONSECUTIVE
#	define XIEITE_HEADER_ALGORITHMS_FIND_MAXIMUM_CONSECUTIVE

#	include <functional>
#	include <iterator>
#	include <ranges>
#	include "../concepts/functable.hpp"

namespace xieite::algorithms {
	template<std::ranges::range Range, xieite::concepts::Functable<bool(std::ranges::range_const_reference_t<Range>, std::ranges::range_const_reference_t<Range>)> Comparator = std::ranges::equal_to>
	[[nodiscard]] constexpr std::ranges::subrange<std::ranges::iterator_t<Range>> findMaximumConsecutive(Range&& range, const std::ranges::range_const_reference_t<Range> value, Comparator&& comparator = Comparator()) noexcept {
		auto iterator = std::ranges::begin(range);
		const auto rangeEnd = std::ranges::end(range);
		auto currentStart = iterator;
		auto currentEnd = iterator;
		auto resultStart = currentStart;
		auto resultEnd = currentEnd;
		bool previous = false;
		for (; iterator != rangeEnd; ++iterator) {
			const bool current = std::invoke(comparator, value, *iterator);
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

#endif
