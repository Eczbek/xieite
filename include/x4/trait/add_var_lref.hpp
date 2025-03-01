#pragma once

#include "../trait/addlrefreft.hpp"
#include "../trait/addvar.hpp"

namespace x4 {
	template<typename T>
	using addvarlref = x4::add_var<x4::add_lrefreft<T>>;
}
