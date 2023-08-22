#ifndef XIEITE_HEADER__MATH__MEDIAN
#	define XIEITE_HEADER__MATH__MEDIAN

#	include <array>
#	include <iterator>
#	include <ranges>
#	include "../concepts/Arithmetic.hpp"
#	include "../math/Result.hpp"
#	include "../math/mean.hpp"
#	include "../types/count.hpp"

namespace xieite::math {
	template<std::ranges::range Range>
	requires(xieite::concepts::Arithmetic<std::ranges::range_value_t<Range>>)
	constexpr xieite::math::Result<std::ranges::range_value_t<Range>> median(const Range& range) noexcept {
		const std::size_t rangeSize = std::ranges::size(range);
		if (!rangeSize) {
			return 0;
		}
		if (rangeSize % 2) {
			return *std::ranges::next(std::ranges::begin(range), (rangeSize - 1) / 2);
		}
		return xieite::math::mean(*std::ranges::next(std::ranges::begin(range), rangeSize / 2 - 1), *std::ranges::next(std::ranges::begin(range), rangeSize / 2));
	}

	template<xieite::concepts::Arithmetic... Arithmetics>
	constexpr xieite::math::Result<Arithmetics...> median(const Arithmetics... values) noexcept {
		const std::array<xieite::math::Result<Arithmetics...>, xieite::types::count<Arithmetics...>> valuesArray {
			static_cast<xieite::math::Result<Arithmetics...>>(values)...
		};
		if (xieite::types::count<Arithmetics...> % 2) {
			return valuesArray[(xieite::types::count<Arithmetics...> - 1) / 2];
		}
		return xieite::math::mean(valuesArray[xieite::types::count<Arithmetics...> / 2 - 1], valuesArray[xieite::types::count<Arithmetics...> / 2]);
	}
}

#endif
