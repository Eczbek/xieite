#ifndef XIEITE_HEADER__MATH__ANTIMODES
#	define XIEITE_HEADER__MATH__ANTIMODES

#	include <array>
#	include <vector>
#	include "../algorithms/antimodes.hpp"
#	include "../concepts/Numeric.hpp"
#	include "../math/Result.hpp"
#	include "../types/count.hpp"

namespace xieite::math {
	template<xieite::concepts::Numeric... Numbers>
	constexpr std::vector<xieite::math::Result<Numbers...>> antimodes(const Numbers... values) noexcept {
		if constexpr (xieite::types::count<Numbers...>) {
			std::vector<xieite::math::Result<Numbers...>> results;
			for (const typename std::array<xieite::math::Result<Numbers...>, xieite::types::count<Numbers...>>::const_iterator iterator : xieite::algorithms::antimodes(std::array<xieite::math::Result<Numbers...>, xieite::types::count<Numbers...>> {
				static_cast<xieite::math::Result<Numbers...>>(values)...
			})) {
				results.push_back(*iterator);
			}
			return results;
		}
		return std::vector<xieite::math::Result<Numbers...>> {
			0
		};
	}
}

#endif
