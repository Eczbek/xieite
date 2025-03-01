#pragma once

#include "../trait/addrefreft.hpp"
#include "../trait/addvarv.hpp"

namespace x4 {
	template<typename T, typename U>
	using addvarvref = x4::add_varv<x4::add_refreft<T, U>>;
}
