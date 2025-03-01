#pragma once

#include "../trait/isarith.hpp"

namespace x4 {
	template<x4::isarith T>
	struct intv {
		T start;
		T end;
	};
}
