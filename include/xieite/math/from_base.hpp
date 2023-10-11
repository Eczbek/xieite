#ifndef XIEITE_HEADER_MATH_FROM_BASE
#	define XIEITE_HEADER_MATH_FROM_BASE

#	include <concepts>
#	include <cstddef>
#	include <string>
#	include <string_view>
#	include "../strings/lowercase.hpp"

namespace xieite::math {
	template<std::integral Integer = int>
	[[nodiscard]] constexpr Integer fromBase(const std::string_view value, const int radix, const std::string_view digits = "0123456789abcdefghijklmnopqrstuvwxyz", const char negativeSign = '-', const bool caseSensitive = false) noexcept {
		if (!radix || !value.size()) {
			return 0;
		}
		Integer result = 0;
		Integer power = 1;
		const bool valueNegative = value[0] == negativeSign;
		const std::string usedDigits = caseSensitive ? std::string(digits) : xieite::strings::lowercase(digits);
		for (std::size_t i = value.size(); i-- > valueNegative;) {
			const std::size_t index = digits.find(value[i]);
			result += static_cast<Integer>(index * (index != std::string::npos) * power);
			power *= radix;
		}
		return valueNegative ? -result : result;
	}
}

#endif
