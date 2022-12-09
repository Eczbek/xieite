#pragma once
#include <concepts> // std::integral
#include <string> // std::string
#include <string_view> // std::string_view
#include <type_traits> // std::make_unsigned_t

namespace xieite::math {
	template<std::integral N = int>
	[[nodiscard]]
	constexpr std::string toBase(N value, const unsigned int base, const std::string_view digits = "0123456789abcdefghijklmnopqrstuvwxyz") noexcept {
		std::make_unsigned_t<N> abs = static_cast<std::make_unsigned_t<N>>(value);
		std::string result;
		do {
			result = digits[abs % base] + result;
			abs /= base;
		} while (abs);
		return result;
	}
}
