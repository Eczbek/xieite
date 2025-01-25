#pragma once

#include "../trait/add_lref.hpp"
#include "../trait/add_v.hpp"

namespace xieite {
	template<typename T>
	using add_vlref = xieite::add_v<xieite::add_lref<T>>;
}
