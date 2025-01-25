#pragma once

#include "../trait/rm_c.hpp"
#include "../trait/rm_rref.hpp"

namespace xieite {
	template<typename T>
	using rm_crref = xieite::rm_c<xieite::rm_rref<T>>;
}
