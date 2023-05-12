#pragma once

#include <cstddef>
#include <functional>
#include <iterator>
#include <ranges>
#include <xieite/concepts/Function.hpp>

namespace xieite::algorithms {
	template<std::forward_iterator Iterator, xieite::concepts::Function<bool(std::iter_value_t<Iterator>, std::iter_value_t<Iterator>)> Callback = std::ranges::equal_to>
	[[nodiscard]]
	constexpr bool isPalindrome(Iterator begin, std::sentinel_for<Iterator> auto end, const Callback& comparator = Callback()) {
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
