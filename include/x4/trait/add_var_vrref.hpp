#pragma once

#include "../trait/addrrefreft.hpp"
#include "../trait/addvarv.hpp"

namespace x4 {
	template<typename T>
	using addvarvrref = x4::add_varv<x4::add_rrefreft<T>>;
}
