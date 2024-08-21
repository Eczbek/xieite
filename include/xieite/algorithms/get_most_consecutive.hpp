#ifndef XIEITE_HEADER_ALGORITHMS_GET_MOST_CONSECUTIVE
#	define XIEITE_HEADER_ALGORITHMS_GET_MOST_CONSECUTIVE

#	include <functional>
#	include <iterator>
#	include <ranges>
#	include <type_traits>
#	include "../concepts/functor.hpp"

namespace xieite::algorithms {
	template<std::ranges::input_range Range, xieite::concepts::Functor<bool(std::ranges::range_reference_t<Range>)> Functor>
	[[nodiscard]] constexpr std::ranges::subrange<std::ranges::iterator_t<Range>> getMostConsecutive(Range& range, Functor&& selector = Functor())
	noexcept(std::is_nothrow_invocable_v<Functor, std::ranges::range_reference_t<Range>>) {
		auto iterator = std::ranges::begin(range);
		const auto rangeEnd = std::ranges::end(range);
		auto currentStart = iterator;
		auto currentEnd = iterator;
		auto resultStart = currentStart;
		auto resultEnd = currentEnd;
		bool previous = false;
		for (; iterator != rangeEnd; ++iterator) {
			const bool current = std::invoke(selector, *iterator);
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
