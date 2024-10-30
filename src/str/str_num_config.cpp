export module xieite:str_num_config;

import std;
import :chars;

export namespace xieite {
	struct str_num_config {
		std::string_view digits = xieite::chars::alphanum;
		std::string_view neg = "-";
		std::string_view pos = "+";
		std::string_view points = ".";
		std::string_view exp = "Ee";
		std::size_t prec = 50;
	};
}
