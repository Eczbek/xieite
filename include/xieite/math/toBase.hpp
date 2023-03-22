#pragma once

#include <concepts>
#include <cstddef>
#include <string>
#include <string_view>
#include <type_traits>

namespace xieite::math {
	template<std::integral Integral = int>
	[[nodiscard]]
	constexpr std::string toBase(Integral value, const std::size_t base, const std::string_view digits = "0123456789abcdefghijklmnopqrstuvwxyz") noexcept {
		std::make_unsigned_t<Integral> abs = static_cast<std::make_unsigned_t<Integral>>(value);
		std::string result;
		do {
			result = digits[abs % base] + result;
			abs /= base;
		} while (abs);
		return result;
	}
}
