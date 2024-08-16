#ifndef XIEITE_HEADER_ALGORITHMS_IS_UNIFORM_MATRIX
#	define XIEITE_HEADER_ALGORITHMS_IS_UNIFORM_MATRIX

#	include <algorithm>
#	include <ranges>
#	include "../macros/lift.hpp"

namespace xieite::algorithms {
	template<std::ranges::input_range Range>
	requires(std::ranges::input_range<std::ranges::range_value_t<Range>>)
	[[nodiscard]] constexpr bool isUniformMatrix(Range&& matrix) noexcept {
		if constexpr (std::ranges::input_range<std::ranges::range_value_t<std::ranges::range_value_t<Range>>>) {
			return std::ranges::all_of(matrix, XIEITE_LIFT(xieite::algorithms::isUniformMatrix));
		} else {
			const std::size_t firstSize = std::ranges::size(*std::ranges::begin(matrix));
			return std::ranges::all_of(matrix, [firstSize](const std::ranges::range_const_reference_t<Range> item) -> bool {
				return std::ranges::size(item) == firstSize;
			});
		}
	}
}

#endif
