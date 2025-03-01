#pragma once

#include "../trait/addnoex.hpp"
#include "../trait/addvarcvref.hpp"

namespace x4 {
	template<typename T, typename U>
	using addvarcvrefnoex = x4::add_varcvref<T, x4::addnoex<U>>;
}
