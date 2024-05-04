#ifndef XIEITE_HEADER_ALGORITHMS_FIND_OCCURRENCE
#	define XIEITE_HEADER_ALGORITHMS_FIND_OCCURRENCE

#	include <cstddef>
#	include <functional>
#	include <ranges>
#	include "../concepts/functable.hpp"
#	include "../concepts/no_throw_invocable.hpp"
#	include "../algorithms/get_occurrence.hpp"

namespace xieite::algorithms {
	template<std::ranges::range Range_, xieite::concepts::Functable<bool(std::ranges::range_reference_t<Range_>, std::ranges::range_reference_t<Range_>)> Functor_ = std::ranges::equal_to>
	[[nodiscard]] constexpr std::ranges::const_iterator_t<Range_> findOccurrence(Range_& range, std::size_t count, const std::ranges::range_reference_t<Range_> value, Functor_&& comparator = Functor_())
	noexcept(xieite::concepts::NoThrowInvocable<Functor_, std::ranges::range_reference_t<Range_>, std::ranges::range_reference_t<Range_>>) {
		return xieite::algorithms::getOccurrence(range, count, [&value](const std::ranges::range_reference_t<Range_> other) {
			return std::invoke(comparator, value, other);
		});
	}
}

#endif
