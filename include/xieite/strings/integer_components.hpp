#ifndef XIEITE_HEADER_STRINGS_INTEGER_COMPONENTS
#	define XIEITE_HEADER_STRINGS_INTEGER_COMPONENTS

#	include <string>
#	include <string_view>
#	include "../strings/characters.hpp"

namespace xieite::strings {
	struct IntegerComponents {
		std::string digits;
		char negative;
		char positive;
		char point;
		char exponent;

		constexpr IntegerComponents(const std::string_view digits = xieite::strings::characters::alphanumeric, const char negative = '-', const char positive = '+', const char point = '.', const char exponent = 'e') noexcept
		: digits(digits), negative(negative), positive(positive), point(point), exponent(exponent) {}
	};
}

#endif
