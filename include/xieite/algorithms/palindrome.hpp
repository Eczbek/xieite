#ifndef XIEITE_HEADER_ALGORITHMS_PALINDROME
#	define XIEITE_HEADER_ALGORITHMS_PALINDROME

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
	[[nodiscard]] constexpr bool palindrome(const Range& range, const Functor& comparator = Functor())
	noexcept(xieite::concepts::NoThrowInvocable<Functor, std::ranges::range_reference_t<Range>, std::ranges::range_reference_t<Range>>) {
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
	[[nodiscard]] constexpr bool palindrome(const Integer value, const std::size_t base = 10) noexcept {
		return value == xieite::math::reverse(value, base);
	}
}

#endif
