#ifndef XIEITE_HEADER__ALGORITHMS__MEDIAN
#	define XIEITE_HEADER__ALGORITHMS__MEDIAN

#	include <algorithm>
#	include <array>
#	include <iterator>
#	include <ranges>
#	include "../algorithms/mean.hpp"
#	include "../concepts/Numeric.hpp"
#	include "../math/Result.hpp"

namespace xieite::algorithms {
	template<std::ranges::range Range>
	requires(xieite::concepts::Numeric<std::ranges::range_value_t<Range>>)
	constexpr xieite::math::Result<std::ranges::range_value_t<Range>> median(Range range) noexcept {
		const std::size_t rangeSize = std::ranges::size(range);
		if (!rangeSize) {
			return 0;
		}
		std::ranges::sort(range);
		if (rangeSize % 2) {
			return *std::ranges::next(std::ranges::begin(range), (rangeSize - 1) / 2);
		}
		return xieite::algorithms::mean(*std::ranges::next(std::ranges::begin(range), rangeSize / 2 - 1), *std::ranges::next(std::ranges::begin(range), rangeSize / 2));
	}

	template<xieite::concepts::Numeric... Numbers>
	constexpr xieite::math::Result<Numbers...> median(const Numbers... values) noexcept {
		return xieite::algorithms::median(std::array<xieite::math::Result<Numbers...>, xieite::types::count<Numbers...>> valuesArray {
			static_cast<xieite::math::Result<Numbers...>>(values)...
		});
	}
}

#endif
