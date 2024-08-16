#ifndef XIEITE_HEADER_ALGORITHMS_GET_OCCURRENCE
#	define XIEITE_HEADER_ALGORITHMS_GET_OCCURRENCE

#	include <cstddef>
#	include <functional>
#	include <ranges>
#	include "../concepts/functor.hpp"
#	include "../concepts/no_throw_invocable.hpp"

namespace xieite::algorithms {
	template<std::ranges::input_range Range, xieite::concepts::Functor<bool(std::ranges::range_reference_t<Range>)> Functor>
	[[nodiscard]] constexpr std::ranges::const_iterator_t<Range> getOccurrence(Range& range, std::size_t count, Functor&& selector = Functor())
	noexcept(xieite::concepts::NoThrowInvocable<Functor, std::ranges::range_reference_t<Range>>) {
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
