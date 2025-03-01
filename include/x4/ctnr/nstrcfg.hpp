#pragma once

#include <cstddef>
#include <string_view>
#include "../ctnr/ch.hpp"

namespace x4 {
	struct nstrcfg {
		std::string_view digit = x4::ch::alphanum;
		std::string_view minus = "-";
		std::string_view plus = "+";
		std::string_view pt = ".";
		std::string_view e = "Ee";
		std::size_t prec = 50;
	};
}
