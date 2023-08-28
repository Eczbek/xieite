#ifndef XIEITE_HEADER__ALGORITHMS__ANTIMODE
#	define XIEITE_HEADER__ALGORITHMS__ANTIMODE

#	include <algorithm>
#	include <array>
#	include <ranges>
#	include "../concepts/Numeric.hpp"
#	include "../math/Result.hpp"
#	include "../types/count.hpp"

namespace xieite::algorithms {
	template<std::ranges::range Range>
	requires(xieite::concepts::Numeric<std::ranges::range_value_t<Range>>)
	constexpr xieite::math::Result<std::ranges::range_value_t<Range>> mode(const Range& range) noexcept {
		return std::ranges::size(range) ? *std::ranges::min_element(range) : 0;
	}

	template<xieite::concepts::Numeric... Numbers>
	constexpr xieite::math::Result<Numbers...> mode(const Numbers... values) noexcept {
		return xieite::algorithms::mode(std::array<xieite::math::Result<Numbers...>, xieite::types::count<Numbers...>> {
			static_cast<xieite::math::Result<Numbers...>>(values)...
		});
	}
}

#endif
