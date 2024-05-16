#ifndef XIEITE_HEADER_STRINGS_INTEGER_COMPONENTS
#	define XIEITE_HEADER_STRINGS_INTEGER_COMPONENTS

#	include <string_view>
#	include "../strings/characters.hpp"

namespace xieite::strings {
	struct NumberComponents {
		std::string_view digits = xieite::strings::characters::alphanumeric;
		std::string_view negatives = "-";
		std::string_view positives = "+";
		std::string_view points = ".";
		std::string_view exponents = "Ee";
		std::size_t precision = 50;
	};
}

#endif
