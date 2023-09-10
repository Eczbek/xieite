#ifndef XIEITE_HEADER__MATH__BASE_TO
#	define XIEITE_HEADER__MATH__BASE_TO

#	include <concepts>
#	include <string>
#	include "../math/AttemptUnsign.hpp"
#	include "../math/Base.hpp"
#	include "../math/absolute.hpp"

namespace xieite::math {
	template<std::integral Integer>
	constexpr std::string toBase(const xieite::math::Base& base, Integer value) noexcept {
		if (!base.radix || !value) {
			return std::string(1, base.digit(0));
		}
		std::string result;
		xieite::math::AttemptUnsign<Integer> absoluteValue = xieite::math::absolute(value);
		if (base.radix == 1) {
			result = std::string(absoluteValue, base.digit(1));
		} else {
			if (base.radix == -1) {
				result = base.digit(1);
				while (absoluteValue-- > 1) {
					result += std::string(1, base.digit(0)) + base.digit(1);
				}
			} else {
				const unsigned int absoluteBase = xieite::math::absolute(base.radix);
				while (value) {
					Integer remainder = value % base.radix;
					value /= base.radix;
					if (remainder < 0) {
						remainder += absoluteBase;
						++value;
					}
					result = base.digit(remainder) + result;
				}
			}
		}
		if (value < 0) {
			result = base.negativeSign + result;
		}
		return result;
	}
}

#endif
