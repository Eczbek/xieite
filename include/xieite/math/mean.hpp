#ifndef XIEITE_HEADER__MATH__MEAN
#	define XIEITE_HEADER__MATH__MEAN

#	include "../concepts/Numeric.hpp"
#	include "../math/Result.hpp"
#	include "../types/count.hpp"

namespace xieite::math {
	template<xieite::concepts::Numeric... Numbers>
	constexpr xieite::math::Result<Numbers...> mean(const Numbers... values) noexcept {
		if constexpr (xieite::types::count<Numbers...>) {
			return (... + (static_cast<xieite::math::Result<Numbers...>>(values) / xieite::types::count<Numbers...>));
		}
		return 0;
	}
}

#endif
