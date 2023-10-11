#ifndef XIEITE_HEADER_ALGORITHMS_MEDIAN
#	define XIEITE_HEADER_ALGORITHMS_MEDIAN

#	include <algorithm>
#	include <array>
#	include <cstddef>
#	include <iterator>
#	include <ranges>
#	include "../algorithms/mean.hpp"
#	include "../concepts/numeric.hpp"
#	include "../math/result.hpp"

namespace xieite::algorithms {
	template<std::ranges::range Range>
	requires(xieite::concepts::Numeric<std::ranges::range_value_t<Range>>)
	[[nodiscard]] constexpr xieite::math::Result<std::ranges::range_value_t<Range>> median(Range range) noexcept {
		const std::size_t rangeSize = std::ranges::size(range);
		if (!rangeSize) {
			return 0;
		}
		std::ranges::sort(range);
		return (rangeSize % 2) ? *std::ranges::next(std::ranges::begin(range), (rangeSize - 1) / 2) : xieite::algorithms::mean(*std::ranges::next(std::ranges::begin(range), rangeSize / 2 - 1), *std::ranges::next(std::ranges::begin(range), rangeSize / 2));
	}
}

#endif
