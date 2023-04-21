#pragma once

#include <array>
#include <concepts>
#include <cstddef>
#include <limits>
#include <string_view>

namespace xieite::math {
	template<std::integral Integral = int>
	[[nodiscard]]
	constexpr Integral fromBase(const std::string_view value, const std::size_t base, const std::string_view digits = "0123456789abcdefghijklmnopqrstuvwxyz") noexcept {
		const char min = std::numeric_limits<char>::min();
		std::array<std::size_t, std::numeric_limits<char>::max() - min> characterMap;
		const std::size_t digitsSize = digits.size();
		for (std::size_t i = 0; i < digitsSize; ++i) {
			characterMap[digits[i] - min] = i;
		}
		Integral result = 0;
		Integral power = 1;
		for (std::size_t i = value.size(); i--;) {
			result += characterMap[value[i] - min] * power;
			power *= base;
		}
		return result;
	}
}
