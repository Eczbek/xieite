#pragma once

#include "../trait/cpv.hpp"
#include "../trait/cpref.hpp"

namespace x4 {
	template<typename T, typename U>
	using cpvref = x4::cpv<T, x4::cpref<T, U>>;
}
