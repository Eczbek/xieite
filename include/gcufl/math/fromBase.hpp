#pragma once
#include <concepts>
#include <cstddef>
#include <map>
#include <string_view>

namespace gcufl::math {
	template<std::unsigned_integral N = std::size_t>
	constexpr N fromBase(const std::string_view value, const std::size_t base, const std::string_view digits = "0123456789abcdefghijklmnopqrstuvwxyz") noexcept {
		std::map<char, std::size_t> charMap;
		const std::size_t digitsSize = digits.size();
		for (std::size_t i = 0; i < digitsSize; ++i)
			charMap[digits[i]] = i;
		N result = 0;
		N currentBase = 1;
		for (std::size_t i = value.size(); i--;) {
			result += charMap[value[i]] * currentBase;
			currentBase *= base;
		}
		return result;
	}
}
