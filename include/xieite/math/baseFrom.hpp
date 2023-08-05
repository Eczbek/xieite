#ifndef XIEITE_HEADER__MATH__BASE_FROM
#	define XIEITE_HEADER__MATH__BASE_FROM

#	include <array>
#	include <concepts>
#	include <cstddef>
#	include <limits>
#	include <string_view>

namespace xieite::math {
	template<std::integral Integral = int>
	[[nodiscard]]
	constexpr Integral baseFrom(const std::size_t base, const std::string_view value, const std::string_view digits = "0123456789abcdefghijklmnopqrstuvwxyz") noexcept {
		if (!base) {
			return 0;
		}
		if (base == 1) {
			return value.size();
		}
		std::array<std::size_t, std::numeric_limits<unsigned char>::max()> characterMap;
		const std::size_t digitsSize = digits.size();
		for (std::size_t i = 0; i < digitsSize; ++i) {
			characterMap[static_cast<unsigned char>(digits[i])] = i;
		}
		Integral result = 0;
		Integral power = !!base;
		for (std::size_t i = value.size(); i--;) {
			result += characterMap[static_cast<unsigned char>(value[i])] * power;
			power *= base;
		}
		return result;
	}
}

#endif
