#ifndef XIEITE_HEADER__ALGORITHMS__MODES
#	define XIEITE_HEADER__ALGORITHMS__MODES

#	include <array>
#	include <cstddef>
#	include <ranges>
#	include <vector>
#	include "../concepts/Functable.hpp"
#	include "../concepts/Numeric.hpp"

namespace xieite::algorithms {
	template<std::ranges::range Range, xieite::concepts::Functable<bool(std::ranges::range_value_t<Range>, std::ranges::range_value_t<Range>)> GreaterComparator = std::ranges::greater>
	requires(xieite::concepts::Numeric<std::ranges::range_value_t<Range>>)
	constexpr std::vector<std::ranges::const_iterator_t<const Range&>> modes(const Range& range, const GreaterComparator greaterComparator = GreaterComparator()) noexcept {
		std::vector<std::ranges::const_iterator_t<const Range&>> iterators;
		std::ranges::const_iterator_t<const Range&> iterator = std::ranges::next(std::ranges::begin(range));
		const std::size_t rangeSize = std::ranges::size(range);
		if ((rangeSize == 1) || greaterComparator(*std::ranges::begin(range), *iterator)) {
			iterators.push_back(std::ranges::begin(range));
		}
		if (rangeSize < 2) {
			return iterators;
		}
		const std::ranges::const_iterator_t<const Range&> last = std::ranges::prev(std::ranges::end(range));
		for (; iterator != last; iterator = std::ranges::next(iterator)) {
			if (greaterComparator(*iterator, *std::ranges::prev(iterator)) && greaterComparator(*iterator, *std::ranges::next(iterator))) {
				iterators.push_back(iterator);
			}
		}
		if (greaterComparator(*last, *std::ranges::prev(last))) {
			iterators.push_back(last);
		}
		return iterators;
	}
}

#endif
