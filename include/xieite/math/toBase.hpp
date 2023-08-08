#ifndef XIEITE_HEADER__MATH__BASE_TO
#	define XIEITE_HEADER__MATH__BASE_TO

#	include <concepts>
#	include <cstddef>
#	include <stdexcept>
#	include <string>
#	include <string_view>
#	include <type_traits>

namespace xieite::math {
	template<std::integral Integer = int>
	[[nodiscard]]
	constexpr std::string toBase(const std::size_t base, const Integer value, const std::string_view digits = "0123456789abcdefghijklmnopqrstuvwxyz") noexcept {
		if (!base) {
			return "";
		}
		std::make_unsigned_t<Integer> absolute = static_cast<std::make_unsigned_t<Integer>>(value);
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
