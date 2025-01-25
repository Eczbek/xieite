#pragma once

#include "../trait/rm_rref.hpp"
#include "../trait/rm_v.hpp"

namespace xieite {
	template<typename T>
	using rm_vrref = xieite::rm_v<xieite::rm_rref<T>>;
}
