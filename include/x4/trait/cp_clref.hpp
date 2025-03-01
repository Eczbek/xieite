#pragma once

#include "../trait/cpc.hpp"
#include "../trait/cplref.hpp"

namespace x4 {
	template<typename T, typename U>
	using cpclref = x4::cpc<T, x4::cplref<T, U>>;
}
