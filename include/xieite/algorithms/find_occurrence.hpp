#ifndef XIEITE_HEADER_ALGORITHMS_FIND_OCCURRENCE
#	define XIEITE_HEADER_ALGORITHMS_FIND_OCCURRENCE

#	include <cstddef>
#	include <functional>
#	include <ranges>
#	include "../algorithms/get_occurrence.hpp"
#	include "../concepts/functor.hpp"
#	include "../concepts/no_throw_invocable.hpp"

namespace xieite::algorithms {
	template<std::ranges::input_range Range, xieite::concepts::Functor<bool(std::ranges::range_reference_t<Range>, std::ranges::range_reference_t<Range>)> Functor = std::ranges::equal_to>
	[[nodiscard]] constexpr std::ranges::const_iterator_t<Range> findOccurrence(Range& range, std::size_t count, const std::ranges::range_reference_t<Range> value, Functor&& comparator = Functor())
	noexcept(std::is_nothrow_invocable_v<Functor, std::ranges::range_reference_t<Range>, std::ranges::range_reference_t<Range>>) {
		return xieite::algorithms::getOccurrence(range, count, [&value](const std::ranges::range_reference_t<Range> other) -> bool {
			return std::invoke(comparator, value, other);
		});
	}
}

#endif
