#pragma once

#include "../trait/cpcv.hpp"
#include "../trait/cplref.hpp"

namespace x4 {
	template<typename T, typename U>
	using cpcvlref = x4::cpcv<T, x4::cplref<T, U>>;
}
