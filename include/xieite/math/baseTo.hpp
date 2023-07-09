#ifndef XIEITE_HEADER_MATH_BASETO
#	define XIEITE_HEADER_MATH_BASETO

#	include <concepts>
#	include <cstddef>
#	include <stdexcept>
#	include <string>
#	include <string_view>
#	include <type_traits>

namespace xieite::math {
	template<std::integral Integral = int>
	[[nodiscard]]
	constexpr std::string baseTo(const std::size_t base, Integral value, const std::string_view digits = "0123456789abcdefghijklmnopqrstuvwxyz") noexcept {
		if (!base) {
			return "";
		}
		std::make_unsigned_t<Integral> absolute = static_cast<std::make_unsigned_t<Integral>>(value);
		if (base == 1) {
			return std::string(absolute, digits[1]);
		}
		std::string result;
		do {
			result = digits[absolute % base] + result;
			absolute /= base;
		} while (absolute);
		return result;
	}
}

#endif
