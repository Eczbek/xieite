export module xieite:str_num_cfg;

import std;
import :ch;

export namespace xieite {
	struct str_num_cfg {
		std::string_view digits = xieite::ch::alphanum;
		std::string_view neg = "-";
		std::string_view pos = "+";
		std::string_view pts = ".";
		std::string_view exp = "Ee";
		std::size_t prec = 50;
	};
}
