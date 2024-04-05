#ifndef XIEITE_HEADER_ALGORITHMS_FIND_MOST_CONSECUTIVE
#	define XIEITE_HEADER_ALGORITHMS_FIND_MOST_CONSECUTIVE

#	include <functional>
#	include <iterator>
#	include <ranges>
#	include "../algorithms/most_consecutive.hpp"
#	include "../concepts/functable.hpp"
#	include "../concepts/no_throw_invocable.hpp"
#	include "../macros/forward.hpp"

namespace xieite::algorithms {
	template<std::ranges::range Range, xieite::concepts::Functable<bool(std::ranges::range_const_reference_t<Range>, std::ranges::range_const_reference_t<Range>)> Functor = std::ranges::equal_to>
	[[nodiscard]] constexpr std::ranges::subrange<std::ranges::iterator_t<Range>> findMostConsecutive(Range&& range, const std::ranges::range_const_reference_t<Range> value, Functor&& comparator = Functor())
	noexcept(xieite::concepts::NoThrowInvocable<Functor, std::ranges::range_const_reference_t<Range>, std::ranges::range_const_reference_t<Range>>) {
		return xieite::algorithms::mostConsecutive(XIEITE_FORWARD(range), [&value](const std::ranges::range_const_reference_t<Range> other) {
			return std::invoke(comparator, value, other);
		});
	}
}

#endif
