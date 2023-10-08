#ifndef XIEITE_HEADER__ALGORITHMS__PARTIALREVERSE
#	define XIEITE_HEADER__ALGORITHMS__PARTIALREVERSE

#	include <algorithm>
#	include <cstddef>
#	include <functional>
#	include <iterator>
#	include <ranges>
#	include <vector>
#	include "../concepts/Functable.hpp"

namespace xieite::algorithms {
	template<std::ranges::range Range, xieite::concepts::Functable<bool(std::ranges::range_value_t<Range>)> Functor>
	constexpr void partialReverse(Range& range, const Functor& selector) {
		std::ranges::iterator_t<Range&> begin = std::ranges::begin(range);
		std::ranges::const_iterator_t<Range&> end = std::ranges::end(range);
		std::vector<std::ranges::iterator_t<Range&>> iterators;
		for (; begin != end; ++begin) {
			if (std::invoke(selector, *begin)) {
				iterators.push_back(begin);
			}
		}
		const std::size_t iteratorsSize = std::ranges::size(iterators);
		for (std::size_t i = 0; i < (iteratorsSize / 2); ++i) {
			std::ranges::iter_swap(iterators[i], iterators[iteratorsSize - i - 1]);
		}
	}
}

#endif
