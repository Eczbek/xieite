#ifndef XIEITE_HEADER__MATH__BASE_FROM
#	define XIEITE_HEADER__MATH__BASE_FROM

#	include <array>
#	include <concepts>
#	include <cstddef>
#	include <limits>
#	include <string_view>
#	include "../math/splitBoolean.hpp"

namespace xieite::math {
	template<std::integral Integer = int>
	constexpr Integer fromBase(const int base, const std::string_view value, const std::string_view digits = "0123456789abcdefghijklmnopqrstuvwxyz", const char sign = '-') noexcept {
		if (!base || !value.size()) {
			return 0;
		}
		std::array<std::size_t, std::numeric_limits<unsigned char>::max() + 1> digitMap;
		for (std::size_t i = digits.size(); i--;) {
			digitMap[static_cast<unsigned char>(digits[i])] = i;
		}
		Integer result = 0;
		Integer power = 1;
		const bool valueNegative = value[0] == sign;
		for (std::size_t i = value.size(); i-- > valueNegative;) {
			result += static_cast<Integer>(digitMap[static_cast<unsigned char>(value[i])] * power);
			power *= base;
		}
		return result * xieite::math::splitBoolean(!valueNegative);
	}
}

#endif
