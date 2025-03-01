#pragma once

#include "../trait/addnoex.hpp"
#include "../trait/addvarref.hpp"

namespace x4 {
	template<typename T, typename U>
	using addvarrefnoex = x4::add_varref<T, x4::addnoex<U>>;
}
