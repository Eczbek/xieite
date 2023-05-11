#pragma once

#include <cstddef>
#include <functional>
#include <iterator>
#include <xieite/concepts/Function.hpp>

namespace xieite::algorithms {
	template<std::forward_iterator Iterator, xieite::concepts::Function<bool(typename std::iterator_traits<Iterator>::value_type, typename std::iterator_traits<Iterator>::value_type)> Callback = std::equal_to<typename std::iterator_traits<Iterator>::value_type>>
	[[nodiscard]]
	constexpr bool isPalindrome(Iterator begin, Iterator end, const Callback& comparator = Callback()) {
		const std::size_t size = std::distance(begin, end) / 2;
		--end;
		for (std::size_t i = 0; i < size; ++i) {
			if (!comparator(*begin, *end)) {
				return false;
			}
			++begin;
			--end;
		}
		return true;
	}
}
