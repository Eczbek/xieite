#ifndef XIEITE_HEADER_STRINGS_INTEGER_COMPONENTS
#	define XIEITE_HEADER_STRINGS_INTEGER_COMPONENTS

#	include <string>
#	include "../strings/characters.hpp"

namespace xieite::strings {
	struct IntegerComponents {
		const std::string digits = std::string(xieite::strings::characters::alphanumeric);
		const char negative = '-';
		const char positive = '+';
		const char point = '.';
		const char exponent = 'e';
	};
}

#endif
