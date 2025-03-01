#pragma once

#include "../trait/addnoex.hpp"
#include "../trait/addvrefreft.hpp"

namespace x4 {
	template<typename T, typename U>
	using addvrefnoex = x4::add_vrefreft<T, x4::addnoex<U>>;
}
