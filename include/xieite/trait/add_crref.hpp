#pragma once

#include "../trait/add_c.hpp"
#include "../trait/add_rref.hpp"

namespace xieite {
	template<typename T>
	using add_crref = xieite::add_c<xieite::add_rref<T>>;
}
