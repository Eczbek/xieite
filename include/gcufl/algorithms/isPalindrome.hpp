#pragma once

#include <functional>
#include <iterator>


namespace gcufl::algorithms {
	template<std::forward_iterator I>
	bool isPalindrome(I begin, I end, const std::function<bool(const typename std::iterator_traits<I>::value_type, const typename std::iterator_traits<I>::value_type)>& comparator = std::equal_to<const typename std::iterator_traits<I>::value_type>()) noexcept {
		const typename std::iterator_traits<I>::difference_type size = std::distance(begin, end);
		--end;
		for (typename std::iterator_traits<I>::difference_type i = 0; i < size / 2; ++i) {
			if (!comparator(*begin, *end))
				return false;
			++begin;
			--end;
		}
		return true;
	}
}