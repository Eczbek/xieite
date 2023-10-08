#ifndef XIEITE_HEADER__ALGORITHMS__ANTIMODES
#	define XIEITE_HEADER__ALGORITHMS__ANTIMODES

#	include <array>
#	include <cstddef>
#	include <functional>
#	include <ranges>
#	include <vector>
#	include "../concepts/Functable.hpp"
#	include "../concepts/Numeric.hpp"

namespace xieite::algorithms {
	template<std::ranges::range Range, xieite::concepts::Functable<bool(std::ranges::range_value_t<Range>, std::ranges::range_value_t<Range>)> Functor = std::ranges::less>
	requires(xieite::concepts::Numeric<std::ranges::range_value_t<Range>>)
	[[nodiscard]] constexpr std::vector<std::ranges::const_iterator_t<const Range&>> antimodes(const Range& range, const Functor& lesserComparator = Functor()) noexcept {
		std::vector<std::ranges::const_iterator_t<const Range&>> iterators;
		auto iterator = std::ranges::next(std::ranges::begin(range));
		const std::size_t rangeSize = std::ranges::size(range);
		if ((rangeSize == 1) || std::invoke(lesserComparator, *std::ranges::begin(range), *iterator)) {
			iterators.push_back(std::ranges::begin(range));
		}
		if (rangeSize < 2) {
			return iterators;
		}
		const auto last = std::ranges::prev(std::ranges::end(range));
		for (; iterator != last; iterator = std::ranges::next(iterator)) {
			if (std::invoke(lesserComparator, *iterator, *std::ranges::prev(iterator)) && std::invoke(lesserComparator, *iterator, *std::ranges::next(iterator))) {
				iterators.push_back(iterator);
			}
		}
		if (std::invoke(lesserComparator, *last, *std::ranges::prev(last))) {
			iterators.push_back(last);
		}
		return iterators;
	}
}

#endif
