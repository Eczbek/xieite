#ifndef XIEITE_HEADER_ALGORITHMS_MODES
#	define XIEITE_HEADER_ALGORITHMS_MODES

#	include <cstddef>
#	include <functional>
#	include <iterator>
#	include <ranges>
#	include <utility>
#	include <vector>
#	include "../concepts/arithmetic.hpp"
#	include "../concepts/functable.hpp"
#	include "../concepts/no_throw_invocable.hpp"
#	include "../types/common_floating_point.hpp"

namespace xieite::algorithms {
	template<std::ranges::range Range, xieite::concepts::Functable<bool(std::ranges::range_reference_t<Range>, std::ranges::range_reference_t<Range>)> Functor = std::ranges::greater>
	requires(xieite::concepts::Arithmetic<std::ranges::range_value_t<Range>>)
	[[nodiscard]] constexpr std::vector<std::ranges::const_iterator_t<Range&&>> modes(Range&& range, Functor&& comparator = Functor())
	noexcept(xieite::concepts::NoThrowInvocable<Functor, std::ranges::range_reference_t<Range>, std::ranges::range_reference_t<Range>>) {
		std::vector<std::ranges::const_iterator_t<Range&&>> iterators;
		auto iterator = std::ranges::next(std::ranges::begin(std::forward<Range>(range)));
		const std::size_t rangeSize = std::ranges::size(std::forward<Range>(range));
		// If range is empty, invalid iterator is not considered
		if ((rangeSize == 1) || std::invoke(std::forward<Functor>(comparator), *std::ranges::begin(std::forward<Range>(range)), *iterator)) {
			iterators.push_back(std::ranges::begin(std::forward<Functor>(range)));
		}
		if (rangeSize < 2) {
			return iterators;
		}
		const auto last = std::ranges::prev(std::ranges::end(std::forward<Range>(range)));
		for (; iterator != last; iterator = std::ranges::next(iterator)) {
			if (std::invoke(std::forward<Functor>(comparator), *iterator, *std::ranges::prev(iterator)) && std::invoke(std::forward<Functor>(comparator), *iterator, *std::ranges::next(iterator))) {
				iterators.push_back(iterator);
			}
		}
		if (std::invoke(std::forward<Functor>(comparator), *last, *std::ranges::prev(last))) {
			iterators.push_back(last);
		}
		return iterators;
	}
}

#endif
