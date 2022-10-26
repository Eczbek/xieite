#pragma once
#include <concepts>
#include <functional>
#include <iterator>
#include <xieite/concepts/Comparator.hpp>

namespace xieite::algorithms {
	template<std::forward_iterator I, xieite::concepts::Comparator<const typename std::iterator_traits<I>::value_type> F>
	[[nodiscard]]
	constexpr bool isPalindrome(I begin, I end, const F& comparator) noexcept {
		const typename std::iterator_traits<I>::difference_type size = std::distance(begin, end) / 2;
		--end;
		for (typename std::iterator_traits<I>::difference_type i = 0; i < size; ++i) {
			if (!comparator(*begin, *end))
				return false;
			++begin;
			--end;
		}
		return true;
	}

	template<std::forward_iterator I>
	[[nodiscard]]
	constexpr bool isPalindrome(const I begin, const I end) noexcept {
		return xieite::algorithms::isPalindrome(begin, end, std::equal_to<typename std::iterator_traits<I>::value_type>());
	}
}
