#pragma once

#include "../trait/add_c.hpp"
#include "../trait/add_v.hpp"

namespace xieite {
	template<typename T>
	using add_cv = xieite::add_c<xieite::add_v<T>>;
}
