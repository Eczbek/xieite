#ifndef XIEITE_HEADER_ALGORITHMS_SAME_RELATIVE_ORDER
#	define XIEITE_HEADER_ALGORITHMS_SAME_RELATIVE_ORDER

#	include <algorithm>
#	include <cstddef>
#	include <functional>
#	include <iterator>
#	include <ranges>
#	include "../concepts/functable.hpp"

namespace xieite::algorithms {
	template<std::ranges::range Range1, std::ranges::range Range2, xieite::concepts::Functable<bool(std::ranges::range_value_t<Range1>, std::ranges::range_value_t<Range2>)> Functor = std::ranges::equal_to>
	[[nodiscard]] constexpr bool sameRelativeOrder(const Range1& range1, Range2 range2, const Functor& comparator = Functor()) {
		const std::size_t rangeSize = std::ranges::size(range1);
		if (rangeSize == std::ranges::size(range2)) {
			for (std::size_t i = 0; i < rangeSize; ++i) {
				if (std::ranges::equal(range1, range2, comparator)) {
					return true;
				}
				std::ranges::rotate(range2, std::ranges::next(std::ranges::begin(range2)));
			}
		}
		return false;
	}
}

#endif