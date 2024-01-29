#ifndef XIEITE_HEADER_MATH_INTEGER_STRING_COMPONENTS
#	define XIEITE_HEADER_MATH_INTEGER_STRING_COMPONENTS

#	include <string>
#	include <string_view>
#	include "../strings/characters.hpp"

namespace xieite::math {
	struct IntegerStringComponents {
		std::string digits;
		char negative;
		char positive;
		char point;
		char exponent;

		constexpr IntegerStringComponents(const std::string_view digits = xieite::strings::characters::alphanumeric, const char negative = '-', const char positive = '+', const char point = '.', const char exponent = 'e') noexcept
		: digits(digits), negative(negative), positive(positive), point(point), exponent(exponent) {}
	};
}

#endif
