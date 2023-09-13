#ifndef XIEITE_HEADER__MATH__MEDIAN
#	define XIEITE_HEADER__MATH__MEDIAN

#	include <array>
#	include "../algorithms/median.hpp"
#	include "../concepts/Numeric.hpp"
#	include "../math/Result.hpp"
#	include "../types/count.hpp"

namespace xieite::math {	
	template<xieite::concepts::Numeric... Numbers>
	constexpr xieite::math::Result<Numbers...> median(const Numbers... values) noexcept {
		return xieite::algorithms::median(std::array<xieite::math::Result<Numbers...>, xieite::types::count<Numbers...>> {
			static_cast<xieite::math::Result<Numbers...>>(values)...
		});
	}
}

#endif
