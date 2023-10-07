#ifndef XIEITE_HEADER__MATH__MEAN
#	define XIEITE_HEADER__MATH__MEAN

#	include "../concepts/Numeric.hpp"
#	include "../math/Result.hpp"

namespace xieite::math {
	template<xieite::concepts::Numeric... Numbers>
	[[nodiscard]] constexpr xieite::math::Result<Numbers...> mean(const Numbers... values) noexcept {
		if constexpr (sizeof...(Numbers)) {
			return (... + (static_cast<xieite::math::Result<Numbers...>>(values) / sizeof...(Numbers)));
		}
		return 0;
	}
}

#endif
