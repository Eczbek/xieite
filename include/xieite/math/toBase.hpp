#ifndef XIEITE_HEADER__MATH__BASE_TO
#	define XIEITE_HEADER__MATH__BASE_TO

#	include <concepts>
#	include <string>
#	include <string_view>
#	include "../math/AttemptUnsign.hpp"
#	include "../math/absolute.hpp"

namespace xieite::math {
	template<std::integral Integer>
	[[nodiscard]]
	constexpr std::string toBase(const int base, Integer value, const std::string_view digits = "0123456789abcdefghijklmnopqrstuvwxyz", const char sign = '-') noexcept {
		if (!base) {
			return "";
		}
		std::string result;
		xieite::math::AttemptUnsign<Integer> absoluteValue = xieite::math::absolute(value);
		if (base == 1) {
			result = std::string(absoluteValue, digits[1]);
		} else {
			if (base == -1) {
				result += digits[!!value];
				while (absoluteValue-- > 1) {
					result = std::string(1, digits[1]) + digits[0] + result;
				}
			} else {
				const unsigned int absoluteBase = xieite::math::absolute(base);
				while (value) {
					Integer remainder = value % base;
					value /= base;
					if (remainder < 0) {
						remainder += absoluteBase;
						++value;
					}
					result = digits[remainder] + result;
				}
			}
		}
		if (value < 0) {
			result = sign + result;
		}
		return result;
	}
}

#endif
