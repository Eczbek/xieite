#pragma once

#include "../trait/cpc.hpp"
#include "../trait/cpv.hpp"

namespace x4 {
	template<typename T, typename U>
	using cpcv = x4::cpc<T, x4::cpv<T, U>>;
}
