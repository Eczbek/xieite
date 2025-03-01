#pragma once

#include "../trait/addcrefreft.hpp"
#include "../trait/addnoex.hpp"

namespace x4 {
	template<typename T, typename U>
	using addcrefnoex = x4::add_crefreft<T, x4::addnoex<U>>;
}
