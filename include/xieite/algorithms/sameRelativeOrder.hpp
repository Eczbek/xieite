#ifndef XIEITE_HEADER__ALGORITHMS__SAME_RELATIVE_ORDER
#	define XIEITE_HEADER__ALGORITHMS__SAME_RELATIVE_ORDER

#	include <concepts>
#	include <functional>
#	include <iterator>
#	include <ranges>
#	include "../concepts/Functable.hpp"

namespace xieite::algorithms {
	template<std::ranges::range Range1, std::ranges::range Range2, xieite::concepts::Functable<bool(std::ranges::range_value_t<Range1>, std::ranges::range_value_t<Range2>)> Callback = std::ranges::equal_to>
	constexpr bool sameRelativeOrder(const Range1& range1, const Range2& range2, const Callback& comparator = Callback()) {
		std::ranges::const_iterator_t<const Range1&> begin1 = std::ranges::begin(range1);
		std::ranges::const_iterator_t<const Range1&> end1 = std::ranges::end(range1);
		std::ranges::const_iterator_t<const Range2&> begin2 = std::ranges::begin(range2);
		std::ranges::const_iterator_t<const Range2&> end2 = std::ranges::end(range2);
		if (std::ranges::distance(begin1, end1) == std::ranges::distance(begin2, end2)) {
			for (std::ranges::const_iterator_t<const Range1&> i = begin1; i != end1; ++i) {
				std::ranges::const_iterator_t<const Range1&> copy1 = i;
				std::ranges::const_iterator_t<const Range1&> copy2 = begin2;
				while (copy2 != end2) {
					if (copy1 == end1) {
						copy1 = begin1;
					}
					if (!comparator(*copy1, *copy2)) {
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

		// TODO: Consider incorporating std::ranges::mismatch
	}
}

#endif
