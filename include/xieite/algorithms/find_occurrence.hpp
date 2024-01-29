#ifndef XIEITE_HEADER_ALGORITHMS_FIND_OCCURRENCE
#	define XIEITE_HEADER_ALGORITHMS_FIND_OCCURRENCE

#	include <cstddef>
#	include <functional>
#	include <ranges>
#	include <utility>
#	include "../concepts/functable.hpp"
#	include "../concepts/no_throw_invocable.hpp"

namespace xieite::algorithms {
	template<std::ranges::range Range, std::convertible_to<std::ranges::range_value_t<Range>> Value, xieite::concepts::Functable<bool(std::ranges::range_reference_t<Range>, std::ranges::range_reference_t<Range>)> Functor = std::ranges::equal_to>
	[[nodiscard]] constexpr std::ranges::const_iterator_t<Range&&> findOccurrence(Range&& range, Value&& value, std::size_t count, Functor&& comparator = Functor())
	noexcept(xieite::concepts::NoThrowInvocable<Functor, std::ranges::range_reference_t<Range>, std::ranges::range_reference_t<Range>>) {
		const auto end = std::ranges::end(std::forward<Range>(range));
		for (auto begin = std::ranges::begin(std::forward<Range>(range)); begin != end; ++begin) {
			if (std::invoke(std::forward<Functor>(comparator), *begin, std::forward<Value>(value)) && !count--) { // Intentional short-circuit
				return begin;
			}
		}
		return end;
	}
}

#endif
