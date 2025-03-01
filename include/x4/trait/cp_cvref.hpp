#pragma once

#include "../trait/cpcv.hpp"
#include "../trait/cpref.hpp"

namespace x4 {
	template<typename T, typename U>
	using cpcvref = x4::cpcv<T, x4::cpref<T, U>>;
}
