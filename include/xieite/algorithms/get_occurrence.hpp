#ifndef XIEITE_HEADER_ALGORITHMS_GET_OCCURRENCE
#	define XIEITE_HEADER_ALGORITHMS_GET_OCCURRENCE

#	include <cstddef>
#	include <functional>
#	include <ranges>
#	include "../concepts/functable.hpp"
#	include "../concepts/no_throw_invocable.hpp"

namespace xieite::algorithms {
	template<std::ranges::range Range_, xieite::concepts::Functable<bool(std::ranges::range_reference_t<Range_>)> Functor_>
	[[nodiscard]] constexpr std::ranges::const_iterator_t<Range_> getOccurrence(Range_& range, std::size_t count, Functor_&& selector = Functor_())
	noexcept(xieite::concepts::NoThrowInvocable<Functor_, std::ranges::range_reference_t<Range_>>) {
		const auto end = std::ranges::end(range);
		for (auto iterator = std::ranges::begin(range); iterator != end; ++iterator) {
			if (std::invoke(comparator, *iterator) && !count--) {
				return begin;
			}
		}
		return end;
	}
}

#endif
