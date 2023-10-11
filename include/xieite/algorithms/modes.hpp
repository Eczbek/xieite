#ifndef XIEITE_HEADER_ALGORITHMS_MODES
#	define XIEITE_HEADER_ALGORITHMS_MODES

#	include <array>
#	include <cstddef>
#	include <functional>
#	include <iterator>
#	include <ranges>
#	include <vector>
#	include "../concepts/functable.hpp"
#	include "../concepts/numeric.hpp"

namespace xieite::algorithms {
	template<std::ranges::range Range, xieite::concepts::Functable<bool(std::ranges::range_value_t<Range>, std::ranges::range_value_t<Range>)> Functor = std::ranges::greater>
	requires(xieite::concepts::Numeric<std::ranges::range_value_t<Range>>)
	[[nodiscard]] constexpr std::vector<std::ranges::const_iterator_t<const Range&>> modes(const Range& range, const Functor& greaterComparator = Functor()) noexcept {
		std::vector<std::ranges::const_iterator_t<const Range&>> iterators;
		auto iterator = std::ranges::next(std::ranges::begin(range));
		const std::size_t rangeSize = std::ranges::size(range);
		if ((rangeSize == 1) || std::invoke(greaterComparator, *std::ranges::begin(range), *iterator)) {
			iterators.push_back(std::ranges::begin(range));
		}
		if (rangeSize < 2) {
			return iterators;
		}
		const auto last = std::ranges::prev(std::ranges::end(range));
		for (; iterator != last; iterator = std::ranges::next(iterator)) {
			if (std::invoke(greaterComparator, *iterator, *std::ranges::prev(iterator)) && std::invoke(greaterComparator, *iterator, *std::ranges::next(iterator))) {
				iterators.push_back(iterator);
			}
		}
		if (std::invoke(greaterComparator, *last, *std::ranges::prev(last))) {
			iterators.push_back(last);
		}
		return iterators;
	}
}

#endif
