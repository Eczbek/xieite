#pragma once

#include "../trait/addrref.hpp"
#include "../trait/cpcvlref.hpp"

namespace x4 {
	template<typename T, typename U>
	using cllpsref = x4::cpcvlref<T, x4::add_rref<U>>;
}
