#pragma once

#include "../trait/addrrefreft.hpp"
#include "../trait/addvar.hpp"

namespace x4 {
	template<typename T>
	using addvarrref = x4::add_var<x4::add_rrefreft<T>>;
}
