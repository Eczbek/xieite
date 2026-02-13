#ifndef DETAIL_XTE_HEADER_MATH_NUMBER_FORMAT_CONFIG
#	define DETAIL_XTE_HEADER_MATH_NUMBER_FORMAT_CONFIG
#
#	include "../data/string_view.hpp"
#	include "../util/types.hpp"

namespace xte {
	struct number_format_config {
		xte::string_view digits = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
		xte::string_view minus = "-";
		xte::string_view plus = "+";
		xte::string_view point = ".";
		xte::string_view exp = "EePp";
	};
}

#endif
