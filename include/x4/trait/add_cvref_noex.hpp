#pragma once

#include "../trait/addcvrefreft.hpp"
#include "../trait/addnoex.hpp"

namespace x4 {
	template<typename T, typename U>
	using addcvrefnoex = x4::add_cvrefreft<T, x4::addnoex<U>>;
}
