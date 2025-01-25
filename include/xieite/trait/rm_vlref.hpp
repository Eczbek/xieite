#pragma once

#include "../trait/cp_lref.hpp"
#include "../trait/rm_v.hpp"

namespace xieite {
	template<typename T>
	using rm_vlref = xieite::rm_v<xieite::rm_lref<T>>;
}
