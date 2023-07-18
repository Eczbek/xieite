#ifndef XIEITE_HEADER_ALGORITHMS_ISPALINDROME
#	define XIEITE_HEADER_ALGORITHMS_ISPALINDROME

#	include <cstddef>
#	include <functional>
#	include <iterator>
#	include <ranges>
#	include <xieite/concepts/Functable.hpp>

namespace xieite::algorithms {
	template<std::ranges::range Range, xieite::concepts::Functable<bool(std::ranges::range_value_t<Range>, std::ranges::range_value_t<Range>)> Callback = std::ranges::equal_to>
	[[nodiscard]]
	constexpr bool isPalindrome(const Range& range, const Callback& comparator = Callback()) {
		std::ranges::iterator_t<const Range&> begin = std::ranges::begin(range);
		std::ranges::iterator_t<const Range&> end = std::ranges::end(range);
		const std::size_t size = std::ranges::distance(begin, end) / 2;
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
