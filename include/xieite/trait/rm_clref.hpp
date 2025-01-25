#pragma once

#include "../trait/rm_c.hpp"
#include "../trait/rm_lref.hpp"

namespace xieite {
	template<typename T>
	using rm_clref = xieite::rm_c<xieite::rm_lref<T>>;
}
