#ifndef XIEITE_HEADER_ALGORITHMS_FIND_OCCURRENCE
#	define XIEITE_HEADER_ALGORITHMS_FIND_OCCURRENCE

#	include <cstddef>
#	include <functional>
#	include <ranges>
#	include "../concepts/functor.hpp"
#	include "../concepts/no_throw_invocable.hpp"
#	include "../algorithms/get_occurrence.hpp"

namespace xieite::algorithms {
	template<std::ranges::input_range Range, xieite::concepts::Functor<bool(std::ranges::range_reference_t<Range>, std::ranges::range_reference_t<Range>)> Functor = std::ranges::equal_to>
	[[nodiscard]] constexpr std::ranges::const_iterator_t<Range> findOccurrence(Range& range, std::size_t count, const std::ranges::range_reference_t<Range> value, Functor&& comparator = Functor())
	noexcept(xieite::concepts::NoThrowInvocable<Functor, std::ranges::range_reference_t<Range>, std::ranges::range_reference_t<Range>>) {
		return xieite::algorithms::getOccurrence(range, count, [&value](const std::ranges::range_reference_t<Range> other) -> bool {
			return std::invoke(comparator, value, other);
		});
	}
}

#endif
