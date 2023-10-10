#pragma once

#include <algorithm>
#include <array>
#include "../concepts/numeric.hpp"
#include "../math/result.hpp"

namespace xieite::math {
	template<xieite::concepts::Numeric... Numbers>
	[[nodiscard]] constexpr xieite::math::Result<Numbers...> minimum(const Numbers... values) noexcept {
		if constexpr (sizeof...(Numbers)) {
			return std::ranges::min(std::array<xieite::math::Result<Numbers...>, sizeof...(Numbers)> {
				static_cast<xieite::math::Result<Numbers...>>(values)...
			});
		}
		return 0;
	}
}
