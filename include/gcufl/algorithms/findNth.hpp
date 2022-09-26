#pragma once

#include <functional>
#include <iterator>


namespace gcufl::algorithms {
	template<std::forward_iterator I>
	I findNth(I begin, const I end, std::size_t count, const typename std::iterator_traits<I>::value_type& value, const std::function<bool(const typename std::iterator_traits<I>::value_type, const typename std::iterator_traits<I>::value_type)>& comparator = std::equal_to<const typename std::iterator_traits<I>::value_type>()) noexcept {
		for (; begin != end; ++begin)
			if (comparator(*begin, value) && !count--)
				return begin;
		return end;
	}
}
