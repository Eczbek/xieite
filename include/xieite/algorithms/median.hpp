#ifndef XIEITE_HEADER__ALGORITHMS__MEDIAN
#	define XIEITE_HEADER__ALGORITHMS__MEDIAN

#	include <algorithm>
#	include <array>
#	include <cstddef>
#	include <iterator>
#	include <ranges>
#	include "../algorithms/mean.hpp"
#	include "../concepts/Numeric.hpp"
#	include "../math/Result.hpp"

namespace xieite::algorithms {
	template<std::ranges::range Range>
	requires(xieite::concepts::Numeric<std::ranges::range_value_t<Range>>)
	[[nodiscard]] constexpr xieite::math::Result<std::ranges::range_value_t<Range>> median(const Range& range) noexcept {
		const std::size_t rangeSize = std::ranges::size(range);
		if (!rangeSize) {
			return 0;
		}
		const Range copy = range;
		std::ranges::sort(copy);
		if (rangeSize % 2) {
			return *std::ranges::next(std::ranges::begin(copy), (rangeSize - 1) / 2);
		}
		return xieite::algorithms::mean(*std::ranges::next(std::ranges::begin(copy), rangeSize / 2 - 1), *std::ranges::next(std::ranges::begin(copy), rangeSize / 2));
	}
}

#endif
