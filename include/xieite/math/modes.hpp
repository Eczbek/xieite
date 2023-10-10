#pragma once

#include <array>
#include <vector>
#include "../algorithms/modes.hpp"
#include "../concepts/numeric.hpp"
#include "../math/result.hpp"

namespace xieite::math {
	template<xieite::concepts::Numeric... Numbers>
	[[nodiscard]] constexpr std::vector<xieite::math::Result<Numbers...>> modes(const Numbers... values) noexcept {
		if constexpr (sizeof...(Numbers)) {
			std::vector<xieite::math::Result<Numbers...>> results;
			for (const typename std::array<xieite::math::Result<Numbers...>, sizeof...(Numbers)>::const_iterator iterator : xieite::algorithms::modes(std::array<xieite::math::Result<Numbers...>, sizeof...(Numbers)> {
				static_cast<xieite::math::Result<Numbers...>>(values)...
			})) {
				results.push_back(*iterator);
			}
			return results;
		}
		return std::vector<xieite::math::Result<Numbers...>>();
	}
}
