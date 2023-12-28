#ifndef XIEITE_HEADER_MATH_MINIMUM
#	define XIEITE_HEADER_MATH_MINIMUM

#	include <algorithm>
#	include <array>
#	include "../concepts/arithmetic.hpp"
#	include "../math/result.hpp"

namespace xieite::math {
	template<xieite::concepts::Arithmetic... Numbers>
	[[nodiscard]] constexpr xieite::math::Result<Numbers...> minimum(const Numbers... values) noexcept {
		if constexpr (sizeof...(Numbers)) {
			return std::ranges::min(std::array<xieite::math::Result<Numbers...>, sizeof...(Numbers)> {
				static_cast<xieite::math::Result<Numbers...>>(values)...
			});
		}
		return 0;
	}
}

#endif
