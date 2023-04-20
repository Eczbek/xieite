#pragma once

#include <cstddef>
#include <functional>
#include <iterator>
#include <xieite/concepts/CallbackComparator.hpp>

namespace xieite::algorithms {
	template<std::forward_iterator Iterator, xieite::concepts::CallbackComparator<typename std::iterator_traits<Iterator>::value_type> Callback = std::equal_to<typename std::iterator_traits<Iterator>::value_type>>
	[[nodiscard]]
	constexpr bool isPalindrome(Iterator begin, Iterator end, Callback&& comparator = Callback()) noexcept {
		const std::size_t size = std::distance(begin, end) / 2;
		--end;
		for (std::size_t i = 0; i < size; ++i) {
			if (!comparator(*begin, *end))
				return false;
			++begin;
			--end;
		}
		return true;
	}
}
