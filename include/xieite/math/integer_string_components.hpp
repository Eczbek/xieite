#ifndef XIEITE_HEADER_MATH_INTEGER_STRING_COMPONENTS
#	define XIEITE_HEADER_MATH_INTEGER_STRING_COMPONENTS

#	include <string>
#	include <string_view>

namespace xieite::math {
	struct IntegerStringComponents {
		std::string digits = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
		char negative = '-';
		char positive = '+';
		char point = '.';
		char exponent = 'e';

		constexpr IntegerStringComponents() noexcept = default;

		constexpr IntegerStringComponents(const std::string_view digits, const char negative, const char positive, const char point, const char exponent) noexcept
		: digits(digits), negative(negative), positive(positive), point(point), exponent(exponent) {}
	};
}

#endif
