#pragma once
#include <concepts> // std::integral
#include <cstddef> // std::size_t
#include <string> // std::string
#include <string_view> // std::string_view
#include <type_traits> // std::make_unsigned_t

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
