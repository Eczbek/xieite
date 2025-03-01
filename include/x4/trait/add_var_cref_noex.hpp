#pragma once

#include "../trait/addnoex.hpp"
#include "../trait/addvarcref.hpp"

namespace x4 {
	template<typename T, typename U>
	using addvarcrefnoex = x4::add_varcref<T, x4::addnoex<U>>;
}
