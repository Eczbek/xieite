#ifndef XIEITE_HEADER_ALGORITHMS_IS_PALINDROME
#	define XIEITE_HEADER_ALGORITHMS_IS_PALINDROME

#	include <concepts>
#	include <cstddef>
#	include <functional>
#	include <iterator>
#	include <ranges>
#	include "../concepts/functable.hpp"
#	include "../concepts/no_throw_invocable.hpp"
#	include "../math/reverse.hpp"

namespace xieite::algorithms {
	template<std::ranges::range Range, xieite::concepts::Functable<bool(std::ranges::range_reference_t<Range>, std::ranges::range_reference_t<Range>)> Functor = std::ranges::equal_to>
	[[nodiscard]] constexpr bool isPalindrome(Range&& range, Functor&& comparator = Functor())
	noexcept(xieite::concepts::NoThrowInvocable<Functor, std::ranges::range_reference_t<Range>, std::ranges::range_reference_t<Range>>) {
		auto iterator = std::ranges::begin(range);
		auto end = std::ranges::end(range);
		for (std::size_t i = std::ranges::size(range) / 2; i--;) {
			--end;
			if (!std::invoke(comparator, *begin, *end)) {
				return false;
			}
			++begin;
		}
		return true;
	}

	template<std::integral Integer>
	[[nodiscard]] constexpr bool isPalindrome(const Integer value, const Integer radix = 10) noexcept {
		return value == xieite::math::reverse(value, radix);
	}
}

#endif
