#pragma once

#include <concepts>
#include <cstddef>
#include <string>
#include <string_view>


namespace gcufl::math {
	template<std::unsigned_integral N = std::size_t>
	constexpr std::string toBase(N value, const std::size_t base, std::string_view digits = "0123456789abcdefghijklmnopqrstuvwxyz") noexcept {
		std::string result;
		while (value) {
			result = digits[value % base] + result;
			value /= base;
		}
		return result;
	}
}
