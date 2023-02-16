#pragma once
#include <cstddef> // std::size_t
#include <functional> // std::equal_to
#include <iterator> // std::forward_iterator, std::iterator_traits
#include <xieite/concepts/Comparator.hpp>

namespace xieite::algorithms {
	template<std::forward_iterator I, xieite::concepts::Comparator<typename std::iterator_traits<I>::value_type> F>
	[[nodiscard]]
	constexpr bool isPalindrome(I begin, I end, F&& comparator) noexcept {
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

	template<std::forward_iterator I>
	[[nodiscard]]
	constexpr bool isPalindrome(const I begin, const I end) noexcept {
		return xieite::algorithms::isPalindrome(begin, end, std::equal_to<typename std::iterator_traits<I>::value_type>());
	}
}
