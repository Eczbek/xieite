#ifndef XIEITE_HEADER_ALGORITHMS_MODES
#	define XIEITE_HEADER_ALGORITHMS_MODES

#	include <cstddef>
#	include <functional>
#	include <iterator>
#	include <ranges>
#	include <vector>
#	include "../concepts/arithmetic.hpp"
#	include "../concepts/functable.hpp"
#	include "../concepts/no_throw_invocable.hpp"
#	include "../types/common_floating_point.hpp"

namespace xieite::algorithms {
	template<std::ranges::range Range, xieite::concepts::Functable<bool(std::ranges::range_value_t<Range>, std::ranges::range_value_t<Range>)> Functor = std::ranges::greater>
	requires(xieite::concepts::Arithmetic<std::ranges::range_value_t<Range>>)
	[[nodiscard]] constexpr std::vector<std::ranges::const_iterator_t<const Range&>> modes(const Range& range, const Functor& comparator = Functor())
	noexcept(xieite::concepts::NoThrowInvocable<Functor, std::ranges::range_value_t<Range>, std::ranges::range_value_t<Range>>) {
		std::vector<std::ranges::const_iterator_t<const Range&>> iterators;
		auto iterator = std::ranges::next(std::ranges::begin(range));
		const std::size_t rangeSize = std::ranges::size(range);
		if ((rangeSize == 1) || std::invoke(comparator, *std::ranges::begin(range), *iterator)) {
			iterators.push_back(std::ranges::begin(range));
		}
		if (rangeSize < 2) {
			return iterators;
		}
		const auto last = std::ranges::prev(std::ranges::end(range));
		for (; iterator != last; iterator = std::ranges::next(iterator)) {
			if (std::invoke(comparator, *iterator, *std::ranges::prev(iterator)) && std::invoke(comparator, *iterator, *std::ranges::next(iterator))) {
				iterators.push_back(iterator);
			}
		}
		if (std::invoke(comparator, *last, *std::ranges::prev(last))) {
			iterators.push_back(last);
		}
		return iterators;
	}
}

#endif
