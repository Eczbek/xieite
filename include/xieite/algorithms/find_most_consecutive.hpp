#ifndef XIEITE_HEADER_ALGORITHMS_FIND_MOST_CONSECUTIVE
#	define XIEITE_HEADER_ALGORITHMS_FIND_MOST_CONSECUTIVE

#	include <functional>
#	include <iterator>
#	include <ranges>
#	include "../algorithms/get_most_consecutive.hpp"
#	include "../concepts/functable.hpp"
#	include "../concepts/no_throw_invocable.hpp"
#	include "../macros/forward.hpp"

namespace xieite::algorithms {
	template<std::ranges::range Range_, xieite::concepts::Functable<bool(std::ranges::range_const_reference_t<Range_>, std::ranges::range_const_reference_t<Range_>)> Functor_ = std::ranges::equal_to>
	[[nodiscard]] constexpr std::ranges::subrange<std::ranges::iterator_t<Range_>> findMostConsecutive(Range_&& range, const std::ranges::range_const_reference_t<Range_> value, Functor_&& comparator = Functor_())
	noexcept(xieite::concepts::NoThrowInvocable<Functor_, std::ranges::range_const_reference_t<Range_>, std::ranges::range_const_reference_t<Range_>>) {
		return xieite::algorithms::getMostConsecutive(XIEITE_FORWARD(range), [&value](const std::ranges::range_const_reference_t<Range_> other) {
			return std::invoke(comparator, value, other);
		});
	}
}

#endif
