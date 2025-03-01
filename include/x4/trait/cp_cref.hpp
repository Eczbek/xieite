#pragma once

#include "../trait/cpc.hpp"
#include "../trait/cpref.hpp"

namespace x4 {
	template<typename T, typename U>
	using cpcref = x4::cpc<T, x4::cpref<T, U>>;
}
