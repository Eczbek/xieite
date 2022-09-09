#pragma once

#include <concepts>
#include <string>
#include <string_view>


namespace gcufl::math {
	template <std::integral N>
	constexpr std::string toBase(N value, const int base, std::string_view digits = "0123456789abcdefghijklmnopqrstuvwxyz") noexcept {
		std::string result;
		while (value) {
			result = digits[value % base] + result;
			value /= base;
		}
		return result;
	}
}
