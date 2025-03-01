#pragma once

#include "../trait/addc.hpp"
#include "../trait/addref.hpp"

namespace x4 {
	template<typename T, typename U>
	using addcref = x4::add_c<x4::add_ref<T, U>>;
}
