#ifndef XIEITE_HEADER_MATH_MAXIMUM
#	define XIEITE_HEADER_MATH_MAXIMUM

#	include <algorithm>
#	include <array>
#	include "../concepts/arithmetic.hpp"
#	include "../types/common_floating_point.hpp"

namespace xieite::math {
	template<xieite::concepts::Arithmetic... Numbers>
	[[nodiscard]] constexpr xieite::types::CommonFloatingPoint<Numbers...> maximum(const Numbers... values) noexcept {
		if constexpr (sizeof...(Numbers)) {
			return std::ranges::max(std::array<xieite::types::CommonFloatingPoint<Numbers...>, sizeof...(Numbers)> {
				static_cast<xieite::types::CommonFloatingPoint<Numbers...>>(values)...
			});
		}
		return 0;
	}
}

#endif
