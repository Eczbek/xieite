#ifndef XIEITE_HEADER__MATH__BASE_FROM
#	define XIEITE_HEADER__MATH__BASE_FROM

#	include <array>
#	include <concepts>
#	include <cstddef>
#	include <limits>
#	include <string_view>
#	include "../math/divideCeiling.hpp"
#	include "../math/splitBoolean.hpp"

namespace xieite::math {
	template<std::integral Integer = int>
	constexpr Integer fromBase(const int base, const std::string_view value, const std::string_view digits = "0123456789abcdefghijklmnopqrstuvwxyz", const char sign = '-') noexcept {
		if (!base || !value.size()) {
			return 0;
		}
		const bool negative = value[0] == sign;
		const int resultSign = splitBoolean(!negative);
		if (base == 1) {
			return static_cast<Integer>(value.size()) * resultSign;
		}
		const std::size_t valueSize = value.size();
		Integer result = 0;
		if (base == -1) {
			int nextSign = resultSign;
			for (std::size_t i = negative; i < valueSize; ++i) {
				result += (value[i] != digits[0]) * nextSign;
				nextSign *= -1;
			}
			return result;
		}
		std::array<std::size_t, std::numeric_limits<unsigned char>::max() + 1> digitMap;
		const std::size_t digitsSize = digits.size();
		for (std::size_t i = 0; i < digitsSize; ++i) {
			digitMap[static_cast<unsigned char>(digits[i])] = i;
		}
		Integer power = !!base;
		for (std::size_t i = valueSize; i-- > negative;) {
			result += static_cast<Integer>(digitMap[static_cast<unsigned char>(value[i])] * power);
			power *= base;
		}
		return result * resultSign;
	}
}

#endif
