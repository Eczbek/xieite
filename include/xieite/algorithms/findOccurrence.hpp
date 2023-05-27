#ifndef XIEITE_HEADER_ALGORITHMS_FINDOCCURRENCE
#	define XIEITE_HEADER_ALGORITHMS_FINDOCCURRENCE

#	include <cstddef>
#	include <functional>
#	include <ranges>
#	include <xieite/concepts/Functional.hpp>

namespace xieite::algorithms {
	template<std::ranges::range Range, xieite::concepts::Functional<bool(std::ranges::range_value_t<Range>, std::ranges::range_value_t<Range>)> Callback = std::ranges::equal_to>
	[[nodiscard]]
	constexpr std::ranges::const_iterator_t<const Range&> findOccurrence(const Range& range, std::ranges::range_const_reference_t<Range> value, std::size_t count, const Callback& comparator = Callback()) {
		std::ranges::iterator_t<const Range&> begin = std::ranges::begin(range);
		std::ranges::const_iterator_t<const Range&> end = std::ranges::end(range);
		for (; begin != end; ++begin) {
			if (comparator(*begin, value) && !--count) {
				return begin;
			}
		}
		return end;
	}
}

#endif
