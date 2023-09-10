#ifndef XIEITE_HEADER__MATH__BASE_FROM
#	define XIEITE_HEADER__MATH__BASE_FROM

#	include <concepts>
#	include <cstddef>
#	include <string_view>
#	include "../math/Base.hpp"

namespace xieite::math {
	template<std::integral Integer = int>
	constexpr Integer fromBase(const xieite::math::Base& base, const std::string_view value) noexcept {
		if (!base.radix || !value.size()) {
			return 0;
		}
		Integer result = 0;
		Integer power = 1;
		const bool valueNegative = value[0] == base.negativeSign;
		for (std::size_t i = value.size(); i-- > valueNegative;) {
			result += static_cast<Integer>(base.position(value[i]) * power);
			power *= base;
		}
		return valueNegative ? -result : result;
	}
}

#endif
