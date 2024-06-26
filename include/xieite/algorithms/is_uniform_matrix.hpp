#ifndef XIEITE_HEADER_ALGORITHMS_IS_UNIFORM_MATRIX
#	define XIEITE_HEADER_ALGORITHMS_IS_UNIFORM_MATRIX

#	include <ranges>

namespace xieite::algorithms {
	template<std::ranges::range Matrix_>
	requires(std::ranges::range<std::ranges::range_value_t<Matrix_>>)
	[[nodiscard]] constexpr bool isUniformMatrix_(Matrix_&& matrix) noexcept {
		for (const std::ranges::range_const_reference_t<Matrix_> column : matrix) {
			if (std::ranges::size(column) != std::ranges::size(*std::ranges::begin(matrix))) {
				return false;
			}
		}
		return true;
	}
}

#endif
