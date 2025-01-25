#pragma once

#include "../trait/add_c.hpp"
#include "../trait/add_lref.hpp"

namespace xieite {
	template<typename T>
	using add_clref = xieite::add_c<xieite::add_lref<T>>;
}
