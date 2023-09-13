#ifndef XIEITE_HEADER__MATH__BASE_TO
#	define XIEITE_HEADER__MATH__BASE_TO

#	include <concepts>
#	include <string>
#	include <string_view>
#	include "../math/AttemptUnsign.hpp"
#	include "../math/absolute.hpp"

namespace xieite::math {
	template<std::integral Integer>
	constexpr std::string toBase(Integer value, const int radix, const std::string_view digits = "0123456789abcdefghijklmnopqrstuvwxyz", const char negativeSign = '-', const bool caseSensitive = false) noexcept {
		if (!radix || !value) {
			return std::string(1, digits[0]);
		}
		std::string result;
		xieite::math::AttemptUnsign<Integer> absoluteValue = xieite::math::absolute(value);
		if (radix == 1) {
			result = std::string(absoluteValue, digits[1]);
		} else {
			if (radix == -1) {
				result = digits[1];
				while (--absoluteValue) {
					result += std::string(1, digits[0]) + digits[1];
				}
			} else {
				const unsigned int absoluteBase = xieite::math::absolute(radix);
				while (value) {
					Integer remainder = value % radix;
					value /= radix;
					if (remainder < 0) {
						remainder += absoluteBase;
						++value;
					}
					result = digits[remainder * (remainder < digits.size())] + result;
				}
			}
		}
		if (value < 0) {
			result = negativeSign + result;
		}
		return result;
	}
}

#endif
