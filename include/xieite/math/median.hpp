#ifndef XIEITE_HEADER_MATH_MEDIAN
#	define XIEITE_HEADER_MATH_MEDIAN

#	include <algorithm>
#	include <cstddef>
#	include <iterator>
#	include <ranges>
#	include <type_traits>
#	include "../concepts/arithmetic.hpp"
#	include "../math/mean.hpp"
#	include "../ranges/make_array.hpp"

namespace xieite::math {
	template<std::ranges::range Range>
	requires(xieite::concepts::Arithmetic<std::ranges::range_value_t<Range>>)
	[[nodiscard]] constexpr std::common_type_t<double, std::ranges::range_value_t<Range>> median(Range range) noexcept {
		const std::size_t rangeSize = std::ranges::size(range);
		if (!rangeSize) {
			return 0;
		}
		std::ranges::sort(range);
		return (rangeSize % 2) ? *std::ranges::next(std::ranges::begin(range), (rangeSize - 1) / 2) : xieite::math::mean(*std::ranges::next(std::ranges::begin(range), rangeSize / 2 - 1), *std::ranges::next(std::ranges::begin(range), rangeSize / 2));
	}

	template<xieite::concepts::Arithmetic... Numbers>
	[[nodiscard]] constexpr std::common_type_t<double, Numbers...> median(const Numbers... values) noexcept {
		return xieite::math::median(xieite::ranges::makeArray<std::common_type_t<double, Numbers...>>(values...));
	}
}

#endif
