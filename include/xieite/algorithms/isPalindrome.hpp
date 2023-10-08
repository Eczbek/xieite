#ifndef XIEITE_HEADER__ALGORITHMS__IS_PALINDROME
#	define XIEITE_HEADER__ALGORITHMS__IS_PALINDROME

#	include <concepts>
#	include <cstddef>
#	include <functional>
#	include <iterator>
#	include <ranges>
#	include "../concepts/Functable.hpp"
#	include "../math/reverse.hpp"

namespace xieite::algorithms {
	template<std::ranges::range Range, xieite::concepts::Functable<bool(std::ranges::range_value_t<Range>, std::ranges::range_value_t<Range>)> Functor = std::ranges::equal_to>
	[[nodiscard]] constexpr bool isPalindrome(const Range& range, const Functor& comparator = Functor()) {
		auto begin = std::ranges::begin(range);
		auto end = std::ranges::end(range);
		for (std::size_t i = std::ranges::size(range) / 2; i--;) {
			end = std::ranges::prev(end);
			if (!std::invoke(comparator, *begin, *end)) {
				return false;
			}
			begin = std::ranges::next(begin);
		}
		return true;
	}

	template<std::integral Integer>
	[[nodiscard]] constexpr bool isPalindrome(const Integer value, const std::size_t base = 10) noexcept {
		return value == xieite::math::reverse(value, base);
	}
}

#endif
