#pragma once

#include "../trait/cpv.hpp"
#include "../trait/cplref.hpp"

namespace x4 {
	template<typename T, typename U>
	using cpvlref = x4::cpv<T, x4::cplref<T, U>>;
}
