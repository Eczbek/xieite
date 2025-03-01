#pragma once

#include "../trait/addc.hpp"
#include "../trait/addlref.hpp"

namespace x4 {
	template<typename T>
	using addclref = x4::add_c<x4::add_lref<T>>;
}
