#pragma once

#include "../trait/addnoex.hpp"
#include "../trait/addrefreft.hpp"

namespace x4 {
	template<typename T, typename U>
	using addrefnoex = x4::add_refreft<T, x4::addnoex<U>>;
}
