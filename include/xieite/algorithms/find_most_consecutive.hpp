#ifndef XIEITE_HEADER_ALGORITHMS_FIND_MOST_CONSECUTIVE
#	define XIEITE_HEADER_ALGORITHMS_FIND_MOST_CONSECUTIVE

#	include <functional>
#	include <iterator>
#	include <ranges>
#	include <type_traits>
#	include "../algorithms/get_most_consecutive.hpp"
#	include "../concepts/functor.hpp"

namespace xieite::algorithms {
	template<std::ranges::input_range Range, xieite::concepts::Functor<bool(std::ranges::range_const_reference_t<Range>, std::ranges::range_const_reference_t<Range>)> Functor = std::ranges::equal_to>
	[[nodiscard]] constexpr std::ranges::subrange<std::ranges::iterator_t<Range>> findMostConsecutive(Range& range, const std::ranges::range_const_reference_t<Range> value, Functor&& comparator = Functor())
	noexcept(std::is_nothrow_invocable_v<Functor, std::ranges::range_const_reference_t<Range>, std::ranges::range_const_reference_t<Range>>) {
		return xieite::algorithms::getMostConsecutive(range, [&value, &comparator](const std::ranges::range_const_reference_t<Range> other) -> bool {
			return std::invoke(comparator, value, other);
		});
	}
}

#endif
