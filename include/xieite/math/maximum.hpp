#ifndef XIEITE_HEADER__MATH__MAXIMUM
#	define XIEITE_HEADER__MATH__MAXIMUM

#	include <algorithm>
#	include <array>
#	include "../concepts/Numeric.hpp"
#	include "../math/Result.hpp"
#	include "../types/count.hpp"

namespace xieite::math {
	template<xieite::concepts::Numeric... Numbers>
	constexpr xieite::math::Result<Numbers...> maximum(const Numbers... values) noexcept {
		if constexpr (xieite::types::count<Numbers...>) {
			return std::ranges::max(std::array<xieite::math::Result<Numbers...>, xieite::types::count<Numbers...>> {
				static_cast<xieite::math::Result<Numbers...>>(values)...
			});
		}
		return 0;
	}
}

#endif
