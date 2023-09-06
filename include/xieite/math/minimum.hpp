#ifndef XIEITE_HEADER__MATH__MINIMUM
#	define XIEITE_HEADER__MATH__MINIMUM

#	include <algorithm>
#	include <array>
#	include "../concepts/Numeric.hpp"
#	include "../math/Result.hpp"
#	include "../types/count.hpp"

namespace xieite::math {
	template<xieite::concepts::Numeric... Numbers>
	constexpr xieite::math::Result<Numbers...> minimum(const Numbers... values) noexcept {
		if constexpr (xieite::types::count<Numbers...>) {
			return std::ranges::min(std::array<xieite::math::Result<Numbers...>, xieite::types::count<Numbers...>> {
				static_cast<xieite::math::Result<Numbers...>>(values)...
			});
		}
		return 0;
	}
}

#endif
