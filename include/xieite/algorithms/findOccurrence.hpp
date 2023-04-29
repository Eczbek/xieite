#pragma once

#include <cstddef>
#include <functional>
#include <iterator>
#include <xieite/concepts/CallbackComparator.hpp>

namespace xieite::algorithms {
	template<std::forward_iterator Iterator, xieite::concepts::CallbackComparator<typename std::iterator_traits<Iterator>::value_type> Callback = std::equal_to<typename std::iterator_traits<Iterator>::value_type>>
	[[nodiscard]]
	constexpr Iterator findOccurrence(Iterator begin, const Iterator end, const typename std::iterator_traits<Iterator>::value_type& value, std::size_t count, const Callback& comparator = Callback()) {
		for (; begin != end; ++begin) {
			if (comparator(*begin, value) && !--count) {
				return begin;
			}
		}
		return end;
	}
}
