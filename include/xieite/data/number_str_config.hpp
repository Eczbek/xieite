#ifndef DETAIL_XIEITE_HEADER_DATA_NUMBER_STR_CONFIG
#	define DETAIL_XIEITE_HEADER_DATA_NUMBER_STR_CONFIG
#
#	include <cstddef>
#	include <string_view>
#	include "../data/chars.hpp"

namespace xieite {
	struct number_str_config {
		std::string_view digits = xieite::chars::alphanumeric;
		std::string_view minus = "-";
		std::string_view plus = "+";
		std::string_view point = ".";
		std::string_view exp = "EePp";
		std::size_t precision = 50;
	};
}

#endif
