#pragma once

#include "../trait/add_rref.hpp"
#include "../trait/add_v.hpp"

namespace xieite {
	template<typename T>
	using add_vrref = xieite::add_v<xieite::add_rref<T>>;
}
