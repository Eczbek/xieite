#ifndef XIEITE_HEADER_ALGORITHMS_ISPALINDROME
#	define XIEITE_HEADER_ALGORITHMS_ISPALINDROME

#	include <cstddef>
#	include <functional>
#	include <iterator>
#	include <ranges>
#	include <xieite/concepts/Function.hpp>

namespace xieite::algorithms {
	template<std::forward_iterator ForwardIterator, std::reverse_iterator ReverseIterator, xieite::concepts::Function<bool(std::iter_value_t<ForwardIterator>, std::iter_value_t<ReverseIterator>)> Callback = std::ranges::equal_to>
	[[nodiscard]]
	constexpr bool isPalindrome(ForwardIterator begin, ReverseIterator end, const Callback& comparator = Callback()) {
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

#endif
