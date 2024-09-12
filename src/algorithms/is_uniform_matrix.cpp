module;

#include <xieite/lift.hpp>

export module xieite:algorithms.isUniformMatrix;

import std;
import :concepts.NoThrowOperableRange;

export namespace xieite::algorithms {
	template<std::ranges::input_range Range>
	requires(std::ranges::input_range<std::ranges::range_value_t<Range>>)
	[[nodiscard]] constexpr bool isUniformMatrix(Range&& matrix)
	noexcept(([]<typename Self, typename Subrange>(this Self self, Subrange) {
		if constexpr (!std::ranges::input_range<Subrange>) {
			return true;
		} else if constexpr (!xieite::concepts::NoThrowOperableRange<Subrange>) {
			return false;
		} else {
			return self(std::declval<std::ranges::range_value_t<Range>>());
		}
	})(std::declval<Range>())) {
		if constexpr (std::ranges::input_range<std::ranges::range_value_t<std::ranges::range_value_t<Range>>>) {
			return std::ranges::all_of(matrix, XIEITE_LIFT(xieite::algorithms::isUniformMatrix));
		} else {
			const std::size_t firstSize = std::ranges::size(*std::ranges::begin(matrix));
			return std::ranges::all_of(matrix, [firstSize](const std::ranges::range_common_reference_t<Range> item) {
				return std::ranges::size(item) == firstSize;
			});
		}
	}
}
