#pragma once

#include "../trait/is_arith.hpp"

namespace xieite {
	template<xieite::is_arith T>
	struct intv {
		T start;
		T end;
	};
}