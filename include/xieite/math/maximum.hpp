#ifndef XIEITE_HEADER__MATH__MAXIMUM
#	define XIEITE_HEADER__MATH__MAXIMUM

#	include <algorithm>
#	include <array>
#	include "../concepts/Numeric.hpp"
#	include "../math/Result.hpp"

namespace xieite::math {
	template<xieite::concepts::Numeric... Numbers>
	[[nodiscard]] constexpr xieite::math::Result<Numbers...> maximum(const Numbers... values) noexcept {
		if constexpr (sizeof...(Numbers)) {
			return std::ranges::max(std::array<xieite::math::Result<Numbers...>, sizeof...(Numbers)> {
				static_cast<xieite::math::Result<Numbers...>>(values)...
			});
		}
		return 0;
	}
}

#endif
