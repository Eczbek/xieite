#ifndef XIEITE_HEADER_ALGORITHMS_IS_ROTATED
#	define XIEITE_HEADER_ALGORITHMS_IS_ROTATED

#	include <algorithm>
#	include <cstddef>
#	include <functional>
#	include <iterator>
#	include <ranges>
#	include <utility>
#	include <vector>
#	include <type_traits>
#	include "../concepts/functor.hpp"

namespace xieite::algorithms {
	template<std::ranges::input_range Range1, std::ranges::input_range Range2, xieite::concepts::Functor<bool(std::ranges::range_reference_t<Range1>, std::ranges::range_reference_t<Range2>)> Functor = std::ranges::equal_to>
	[[nodiscard]] constexpr bool isRotated(Range1&& range1, Range2&& range2, Functor&& comparator = Functor())
	noexcept(std::is_nothrow_invocable_v<Functor, std::ranges::range_reference_t<Range1>, std::ranges::range_reference_t<Range2>>) {
		const auto begin1 = std::ranges::begin(range1);
		const auto end1 = std::ranges::end(range1);
		const auto begin2 = std::ranges::begin(range2);
		const auto end2 = std::ranges::end(range2);
		if (std::ranges::size(range1) == std::ranges::size(range2)) {
			for (auto iterator = begin1; iterator != end1; ++iterator) {
				auto copy1 = iterator;
				auto copy2 = begin2;
				while (copy2 != end2) {
					if (copy1 == end1) {
						copy1 = begin1;
					}
					if (!std::invoke(comparator, *copy1, *copy2)) {
						break;
					}
					++copy1;
					++copy2;
				}
				if (copy2 == end2) {
					return true;
				}
			}
		}
		return false;
	}
}

#endif
