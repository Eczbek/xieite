#ifndef XIEITE_HEADER_ALGORITHMS_IS_ROTATED
#	define XIEITE_HEADER_ALGORITHMS_IS_ROTATED

#	include <algorithm>
#	include <cstddef>
#	include <functional>
#	include <iterator>
#	include <ranges>
#	include <utility>
#	include <vector>
#	include "../concepts/functable.hpp"
#	include "../concepts/no_throw_invocable.hpp"

namespace xieite::algorithms {
	template<std::ranges::range Range1_, std::ranges::range Range2_, xieite::concepts::Functable<bool(std::ranges::range_reference_t<Range1_>, std::ranges::range_reference_t<Range2_>)> Functor_ = std::ranges::equal_to>
	[[nodiscard]] constexpr bool isRotated(Range1_&& range1, Range2_&& range2, Functor_&& comparator = Functor_())
	noexcept(xieite::concepts::NoThrowInvocable<Functor_, std::ranges::range_reference_t<Range1_>, std::ranges::range_reference_t<Range2_>>) {
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
