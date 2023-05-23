#ifndef XIEITE_HEADER_ALGORITHMS_FINDOCCURRENCE
#	define XIEITE_HEADER_ALGORITHMS_FINDOCCURRENCE

#	include <concepts>
#	include <cstddef>
#	include <functional>
#	include <iterator>
#	include <ranges>
#	include <xieite/concepts/Function.hpp>

namespace xieite::algorithms {
	template<std::forward_iterator ForwardIterator, xieite::concepts::Function<bool(std::iter_value_t<ForwardIterator>, std::iter_value_t<ForwardIterator>)> Callback = std::ranges::equal_to>
	[[nodiscard]]
	constexpr ForwardIterator findOccurrence(ForwardIterator begin, const std::sentinel_for<ForwardIterator> auto end, const std::convertible_to<std::iter_value_t<ForwardIterator>> auto& value, std::size_t count, const Callback& comparator = Callback()) {
		for (; begin != end; ++begin) {
			if (comparator(*begin, value) && !--count) {
				return begin;
			}
		}
		return end;
	}
}

#endif
