#ifndef XIEITE_HEADER_ALGORITHMS_SAME_RELATIVE_ORDER
#	define XIEITE_HEADER_ALGORITHMS_SAME_RELATIVE_ORDER

#	include <algorithm>
#	include <cstddef>
#	include <functional>
#	include <iterator>
#	include <ranges>
#	include <utility>
#	include <vector>
#	include "../concepts/functable.hpp"
#	include "../concepts/no_throw_invocable.hpp"

namespace xieite::algorithms {
	template<std::ranges::range Range1, std::ranges::range Range2, xieite::concepts::Functable<bool(std::ranges::range_reference_t<Range1>, std::ranges::range_reference_t<Range2>)> Functor = std::ranges::equal_to>
	[[nodiscard]] constexpr bool sameRelativeOrder(Range1&& range1, Range2&& range2, Functor&& comparator = Functor())
	noexcept(xieite::concepts::NoThrowInvocable<Functor, std::ranges::range_reference_t<Range1>, std::ranges::range_reference_t<Range2>>) {
		const std::ranges::const_iterator_t<Range1&&> begin1 = std::ranges::begin(std::forward<Range1>(range1));
		const std::ranges::const_iterator_t<Range1&&> end1 = std::ranges::end(std::forward<Range1>(range1));
		const std::ranges::const_iterator_t<Range2&&> begin2 = std::ranges::begin(std::forward<Range1>(range2));
		const std::ranges::const_iterator_t<Range2&&> end2 = std::ranges::end(std::forward<Range1>(range2));
		if (std::ranges::size(std::forward<Range1>(range1)) == std::ranges::size(std::forward<Range1>(range2))) {
			for (std::ranges::const_iterator_t<Range1&&> i = begin1; i != end1; i = std::ranges::next(i)) {
				std::ranges::const_iterator_t<Range1&&> copy1 = i;
				std::ranges::const_iterator_t<Range1&&> copy2 = begin2;
				while (copy2 != end2) {
					if (copy1 == end1) {
						copy1 = begin1;
					}
					if (!std::invoke(std::forward<Functor>(comparator), *copy1, *copy2)) {
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

#endif
