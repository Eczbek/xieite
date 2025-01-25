#pragma once

#include "../trait/is_arith.hpp"

namespace xieite {
	template<xieite::is_arith T>
	struct interval {
		T start;
		T end;
	};
}
