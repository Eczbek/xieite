#ifndef XIEITE_HEADER_STRINGS_INTEGER_COMPONENTS
#	define XIEITE_HEADER_STRINGS_INTEGER_COMPONENTS

#	include <string_view>
#	include "../strings/characters.hpp"

namespace xieite::strings {
	struct IntegerComponents {
		const std::string_view digits = xieite::strings::characters::alphanumeric;
		const std::string_view negatives = "-";
		const std::string_view positives = "+";
		const std::string_view points = ".";
		const std::string_view exponents = "Ee";
	};
}

#endif
